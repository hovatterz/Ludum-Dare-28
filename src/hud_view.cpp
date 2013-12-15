#include <termbox.h>

#include "termbox_helpers.h"

#include "hud_view.h"

HUDView::HUDView(int x, int y, int width, int height) : View(x, y, width, height) {}

void HUDView::render() {
  tb_fill(x_, y_, 1, height_, '|');
  tb_draw_string(x_ + 1, y_, "Name: Some Player");
  tb_draw_string(x_ + 1, y_ + 1, "HP: 16/43");
  tb_draw_string(x_ + 1, y_ + height_ * 0.5f, "Items:");
}
