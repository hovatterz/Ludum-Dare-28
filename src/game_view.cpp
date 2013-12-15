#include <iostream>
#include <termbox.h>

#include "aspect.h"
#include "field_of_view.h"
#include "spatial.h"

#include "game_view.h"

GameView::GameView(int x, int y, int width, int height, Game *game)
  : View(x, y, width, height),
    center_x_(0),
    center_y_(0),
    game_(game) {
    }

void GameView::set_center(int x, int y) {
  center_x_ = x;
  center_y_ = y;
}

void GameView::render() {
  int low_x = center_x_ - width_ * 0.5f;
  int low_y = center_y_ - height_ * 0.5f;
  int high_x = center_x_ + width_ * 0.5f;
  int high_y = center_y_ + height_ * 0.5f;

  Dungeon *dungeon = game_->dungeon();
  auto fov = game_->player().component<FieldOfView>();

  int i = 0, j = 0;
  for (int x = low_x; x < high_x; ++x) {
    for (int y = low_y; y < high_y; ++y) {
      Tile *tile = dungeon->tile_at(x, y);
      if (tile == nullptr) {
        ++j;
        continue;
      }

      if (fov->visible(x, y) == true) {
        tb_change_cell(i, j, tile->symbol(), tile->foreground(), tile->background());
      }
      ++j;
    }

    ++i;
    j = 0;
  }

  for (auto entity : game_->entities()->entities_with_components<Aspect, Spatial>()) {
    if (entity.valid() == false) { continue; }
    auto spatial = entity.component<Spatial>();
    if (spatial->x() >= low_x && spatial->y() >= low_y &&
        spatial->x() < high_x && spatial->y() < high_y) {
      if (fov->visible(spatial->x(), spatial->y()) == true) {
        auto aspect = entity.component<Aspect>();
        tb_change_cell(spatial->x() - low_x, spatial->y() - low_y,
                       aspect->symbol(), aspect->foreground(), aspect->background());
      }
    }
  }
}
