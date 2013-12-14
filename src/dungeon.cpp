#include "dungeon.h"

Dungeon::Dungeon() : current_level_(0) {}

void Dungeon::generate(int levels, int width, int height) {
  width_ = width;
  height_ = height;

  levels_.clear();

  for (int i = 0; i < levels; ++i) {
    levels_.push_back(Level());
    levels_[i].generate(width_, height_);
  }
}

int Dungeon::height() const {
  return height_;
}

int Dungeon::width() const {
  return width_;
}

Tile *Dungeon::tile_at(int x, int y) {
  Level *level = &levels_[current_level_];
  if (level == nullptr) { return nullptr; }
  return level->tile_at(x, y);
}
