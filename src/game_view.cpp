#include <iostream>
#include <termbox.h>

#include "game_view.h"

GameView::GameView(int x, int y, Game *game) : View(x, y), game_(game) {}

void GameView::render() {
  Dungeon *dungeon = game_->dungeon();
  for (int x = 0; x < dungeon->width(); ++x) {
    for (int y = 0; y < dungeon->height(); ++y) {
      Tile *tile = dungeon->tile_at(x, y);
      if (tile == nullptr) { continue; }
      tb_change_cell(x, y, tile->symbol(), tile->foreground(), tile->background());
    }
  }
}
