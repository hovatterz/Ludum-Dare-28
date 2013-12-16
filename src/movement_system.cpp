#include <map>

#include "events.h"
#include "faction_member.h"
#include "health.h"
#include "rng.h"
#include "spatial.h"
#include "turn_taker.h"

#include "movement_system.h"

struct Direction {
  int x, y;
  Direction() : x(0), y(0) {}
  Direction(int x, int y) : x(x), y(y) {}
};
static std::map<Action, Direction> move_directions;

MovementSystem::MovementSystem() {
  move_directions[kActionMoveNorth] = Direction(0, -1);
  move_directions[kActionMoveSouth] = Direction(0, 1);
  move_directions[kActionMoveWest] = Direction(-1, 0);
  move_directions[kActionMoveEast] = Direction(1, 0);
  move_directions[kActionMoveNorthwest] = Direction(-1, -1);
  move_directions[kActionMoveNortheast] = Direction(1, -1);
  move_directions[kActionMoveSouthwest] = Direction(-1, 1);
  move_directions[kActionMoveSoutheast] = Direction(1, 1);
}

void MovementSystem::update(entityx::ptr<entityx::EntityManager> entities,
                            entityx::ptr<entityx::EventManager> events,
                            double delta) {
  for (auto entity : entities->entities_with_components<TurnTaker, Spatial>()) {
    if (entity.valid() == false) { continue; }
    auto turn_taker = entity.component<TurnTaker>();
    Action action = turn_taker->action();
    if (action != kActionMoveNorth &&
        action != kActionMoveWest &&
        action != kActionMoveSouth &&
        action != kActionMoveEast &&
        action != kActionMoveNorthwest &&
        action != kActionMoveNortheast &&
        action != kActionMoveSouthwest &&
        action != kActionMoveSoutheast) {
      // This entity is not schedulde to move. Skip it.
      continue;
    }

    auto direction_iter = move_directions.find(turn_taker->action());
    if (direction_iter == move_directions.end()) {
      // Invalid direction. Skip it.
      turn_taker->set_action(kActionNone);
      continue;
    }

    auto spatial = entity.component<Spatial>();
    int new_x = spatial->x() + direction_iter->second.x;
    int new_y = spatial->y() + direction_iter->second.y;

    bool attacked_something = false;
    for (auto other : entities->entities_with_components<Health, Spatial>()) {
      if (other.valid() == false) { continue; }

      // This is out of scope of movement. Should be refactored probably
      auto other_spatial = other.component<Spatial>();
      if (other_spatial->x() == new_x && other_spatial->y() == new_y) {
        auto faction_member = entity.component<FactionMember>();
        auto other_faction_member = other.component<FactionMember>();
        if (faction_member != nullptr && other_faction_member != nullptr &&
            faction_member->faction() != other_faction_member->faction()) {
          auto other_health = other.component<Health>();
          int damage = Dice(1, 8).roll();
          other_health->offset(-damage);

          events->emit<AttackEvent>(&entity, &other, damage);
          if (other_health->dead() == true) {
            events->emit<DeathEvent>(&other);
            other.destroy();
          }

          attacked_something = true;
        }
      }
    }

    turn_taker->set_action(kActionNone);
    if (attacked_something == true) { continue; }
    spatial->set_position(new_x, new_y);
  }
}
