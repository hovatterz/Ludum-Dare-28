#ifndef LD28_EVENTS_H_
#define LD28_EVENTS_H_

#include <entityx/entityx.h>

struct AttackEvent : public entityx::Event<AttackEvent> {
  AttackEvent(entityx::Entity *attacker, entityx::Entity *defender, int damage) : attacker(attacker), defender(defender), damage(damage) {
  }

  entityx::Entity *attacker;
  entityx::Entity *defender;
  int damage;
};

#endif  // LD28_EVENTS_H_
