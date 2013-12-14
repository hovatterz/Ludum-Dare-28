#ifndef LD28_DUNGEON_H_
#define LD28_DUNGEON_H_

#include <vector>

#include "level.h"

class Dungeon {
 public:
  Dungeon();

  void generate(int levels, int width, int height);

  int height() const;
  int width() const;

  Tile *tile_at(int x, int y);

 private:
  int current_level_, width_, height_;
  std::vector<Level> levels_;
};

#endif  // LD28_DUNGEON_H_
