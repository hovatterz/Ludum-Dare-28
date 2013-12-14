#ifndef LD28_LEVEL_H_
#define LD28_LEVEL_H_

#include <vector>

#include "tile.h"

class Level {
 public:
  void generate(int width, int height);

  int height() const;
  int width() const;

  Tile *tile_at(int x, int y);

 private:
  std::vector<std::vector<Tile>> tiles_;

  int width_, height_;
};

#endif  // LD28_LEVEL_H_
