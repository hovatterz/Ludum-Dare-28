#include <iostream>

#include <termbox.h>

#include "termbox_helpers.h"

#include "announcements_view.h"

AnnouncementsView::AnnouncementsView(int x, int y, int width, int height)
  : View(x, y, width, height) {
  }

void AnnouncementsView::add_announcement(const std::string &announcement) {
  announcements_.push_back(announcement);
}

void AnnouncementsView::render() {
  tb_fill(x_, y_, width_, 1, '-');

  int y_off = 0;
  int num_announcements = static_cast<int>(announcements_.size());
  for (int i = num_announcements - 3; i < num_announcements; ++i) {
    if (i < 0) { continue; }
    tb_draw_string(x_, y_ + 1 + y_off, announcements_[i]);
    ++y_off;
  }
}
