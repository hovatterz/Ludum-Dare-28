#include "health.h"

entityx::ptr<Health> Health::make() {
  return entityx::ptr<Health>(new Health());
}
