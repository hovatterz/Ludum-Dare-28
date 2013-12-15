#ifndef LD28_EVENTS_H_
#define LD28_EVENTS_H_

#include <entityx/entityx.h>

struct AttackEvent : public entityx::Event<AttackEvent> {
  AttackEvent(entityx::Entity *attacker, entityx::Entity *target, int damage) : attacker(attacker), target(target), damage(damage) {
  }

  entityx::Entity *attacker;
  entityx::Entity *target;
  int damage;
};

#endif  // LD28_EVENTS_H_
