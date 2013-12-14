#include <termbox.h>

#include "termbox_helpers.h"

void tb_draw_string(int x, int y, const std::string &str,
                    uint16_t fg, uint16_t bg) {
  for (std::size_t i = 0; i < str.size(); ++i) {
    tb_change_cell(x + i, y, str.at(i), fg, bg);
  }
}

void tb_fill(int x, int y, int w, int h, char symbol,
             uint16_t fg, uint16_t bg) {
  for (int i = x; i < x + w; ++i) {
    for (int j = y; j < y + h; ++j) {
      tb_change_cell(i, j, symbol, fg, bg);
    }
  }
}
