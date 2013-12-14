#ifndef LD28_RNG_H_
#define LD28_RNG_H_

#include <cstdlib>

int rand_range(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}

#endif  // LD28_RNG_H_
