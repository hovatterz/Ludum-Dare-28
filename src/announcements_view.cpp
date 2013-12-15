#include <iostream>

#include <termbox.h>

#include "termbox_helpers.h"

#include "announcements_view.h"

AnnouncementsView::AnnouncementsView(int x, int y, int width, int height,
                                     AnnouncementsReceiver *receiver)
  : View(x, y, width, height),
    receiver_(receiver) {
    }

void AnnouncementsView::render() {
  tb_fill(x_, y_, width_, 1, '-');

  auto &announcements = receiver_->announcements();

  int y_off = 0;
  int num_announcements = static_cast<int>(announcements.size());
  for (int i = num_announcements - 3; i < num_announcements; ++i) {
    if (i < 0) { continue; }
    tb_draw_string(x_, y_ + 1 + y_off, announcements[i]);
    ++y_off;
  }
}
