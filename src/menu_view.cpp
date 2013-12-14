#include <termbox.h>

#include "termbox_helpers.h"

#include "menu_view.h"

MenuView::MenuView(int x, int y) : View(x, y), selected_index_(0) {}

void MenuView::add_item(const std::string &item) {
  items_.push_back(item);
}

int MenuView::selected() const {
  return selected_index_;
}

void MenuView::set_selected(int selected_index) {
  selected_index_ = selected_index;
}

int MenuView::num_items() const {
  return items_.size();
}

void MenuView::render() {
  int i = 0;
  for (auto item : items_) {
    uint16_t fg = TB_WHITE, bg = TB_BLACK;
    if (i == selected_index_) {
      fg = TB_WHITE;
      bg = TB_RED;
    }

    tb_fill(x_, y_ + i, 10, 1, ' ', fg, bg);
    tb_draw_string(x_ + 1, y_ + i, item, fg, bg);
    ++i;
  }
}
