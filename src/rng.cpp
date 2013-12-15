#include "rng.h"

int rand_range(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}
