#include "health.h"

Health::Health() : health_(8), max_health_(8), dice_(1, 8) {}
Health::Health(Dice dice) : health_(dice.sides), max_health_(dice.sides), dice_(dice) {}
entityx::ptr<Health> Health::make(Dice dice) {
  return entityx::ptr<Health>(new Health(dice));
}

int Health::health() const {
  return health_;
}

int Health::max_health() const {
  return max_health_;
}

bool Health::dead() const {
  return health_ <= 0;
}

void Health::offset(int offset) {
  health_ += offset;
}
