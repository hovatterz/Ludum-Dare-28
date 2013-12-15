#include <termbox.h>

#include "game.h"
#include "health.h"
#include "termbox_helpers.h"

#include "hud_view.h"

HUDView::HUDView(int x, int y, int width, int height, Game *game)
  : View(x, y, width, height),
    game_(game) {
    }

void HUDView::render() {
  entityx::Entity player = game_->player();
  if (player.valid() == false) { return; }
  auto health = player.component<Health>();

  tb_fill(x_, y_, 1, height_, '|');

  tb_draw_string(x_ + 1, y_, "Name: Some Player");

  tb_draw_string(x_ + 1, y_ + 1,
                 "HP: " + std::to_string(health->health())
                 + "/" + std::to_string(health->max_health()));

  tb_draw_string(x_ + 1, y_ + height_ * 0.5f, "Items:");
}
