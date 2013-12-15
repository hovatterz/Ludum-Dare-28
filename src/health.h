#ifndef LD28_HEALTH_H_
#define LD28_HEALTH_H_

#include <entityx/entityx.h>

class Health : public entityx::Component<Health> {
 public:
  static entityx::ptr<Health> make();
};

#endif  // LD28_HEALTH_H_
