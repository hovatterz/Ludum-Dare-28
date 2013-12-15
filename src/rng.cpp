#include "rng.h"

int rand_range(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}

int roll_die(int num, int sides) {
  int result = 0;
  for (int i = 0; i < num; ++i) {
    result += rand_range(1, sides);
  }

  return result;
}
