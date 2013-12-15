#include "rng.h"

int rand_range(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}

Dice::Dice(int num, int sides) : num(num), sides(sides) {}

int Dice::roll() const {
  int result = 0;
  for (int i = 0; i < num; ++i) {
    result += rand_range(1, sides);
  }

  return result;
}
