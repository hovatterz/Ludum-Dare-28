#ifndef LD28_HEALTH_H_
#define LD28_HEALTH_H_

#include <entityx/entityx.h>

#include "rng.h"

class Health : public entityx::Component<Health> {
 public:
  Health();
  explicit Health(Dice dice);
  static entityx::ptr<Health> make(Dice dice);

  int health() const;
  int max_health() const;

 private:
  int health_, max_health_;
  Dice dice_;
};

#endif  // LD28_HEALTH_H_
