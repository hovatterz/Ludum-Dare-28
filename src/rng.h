#ifndef LD28_RNG_H_
#define LD28_RNG_H_

#include <cstdlib>

int rand_range(int min, int max);

struct Dice {
  int num, sides;

  Dice(int num, int sides);
  int roll() const;
};

#endif  // LD28_RNG_H_
