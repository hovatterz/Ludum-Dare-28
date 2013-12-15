#include "script.h"
#include "turn_taker.h"

#include "turn_system.h"

void TurnSystem::update(entityx::ptr<entityx::EntityManager> entities,
                        entityx::ptr<entityx::EventManager> events,
                        double delta) {
  for (auto entity : entities->entities_with_components<TurnTaker>()) {
    auto script = entity.component<Script>();
    if (script != nullptr) {
      script->think();
    }
  }
}
