#include "rng.h"

#include "level.h"

void Level::generate(int width, int height) {
  width_ = width;
  height_ = height;

  tiles_.clear();
  tiles_.resize(width_, std::vector<Tile>(height, Tile()));

  for (int x = 0; x < width_; ++x) {
    for (int y = 0; y < height_; ++y) {
      Tile &tile = tiles_[x][y];
      int random = rand_range(0, 1);
      if (random == 0) {
        tile.set_symbol('#');
      } else {
        tile.set_symbol('.');
      }
    }
  }
}

int Level::height() const {
  return height_;
}

int Level::width() const {
  return width_;
}

Tile *Level::tile_at(int x, int y) {
  if (x >= 0 && x < width_ && y >= 0 && y < height_) {
    return &tiles_[x][y];
  }

  return nullptr;
}
