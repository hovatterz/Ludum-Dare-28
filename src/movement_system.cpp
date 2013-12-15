#include <map>

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

    entity.component<Spatial>()->offset_position(direction_iter->second.x,
                                                 direction_iter->second.y);
    turn_taker->set_action(kActionNone);
  }
}
