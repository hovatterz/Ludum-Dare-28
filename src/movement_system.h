#ifndef LD28_MOVEMENT_SYSTEM_H_
#define LD28_MOVEMENT_SYSTEM_H_

#include <entityx/entityx.h>

class MovementSystem : public entityx::System<MovementSystem> {
 public:
  MovementSystem();

  void update(entityx::ptr<entityx::EntityManager> entities,
              entityx::ptr<entityx::EventManager> events,
              double delta) override;
};

#endif  // LD28_MOVEMENT_SYSTEM_H_
