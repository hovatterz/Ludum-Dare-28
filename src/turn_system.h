#ifndef LD28_TURN_SYSTEM_H_
#define LD28_TURN_SYSTEM_H_

#include <entityx/entityx.h>

class TurnSystem : public entityx::System<TurnSystem> {
 public:
  void update(entityx::ptr<entityx::EntityManager> entities,
              entityx::ptr<entityx::EventManager> events,
              double delta) override;
};

#endif  // LD28_TURN_SYSTEM_H_
