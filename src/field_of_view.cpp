#include <cmath>

#include "field_of_view.h"

FieldOfView::FieldOfView() : radius_(0) {}
FieldOfView::FieldOfView(int radius) : radius_(radius) {}
entityx::ptr<FieldOfView> FieldOfView::make(unsigned int radius) {
  return entityx::ptr<FieldOfView>(new FieldOfView(radius));
}

/**
 * C++ implementation of Bjorn Bergstrom's recursive shadowcasting algorithm
 * http://roguebasin.roguelikedevelopment.org/index.php?title=FOV_using_recursive_shadowcasting
 */

static int multipliers[4][8] = {
  {1, 0, 0, -1, -1, 0, 0, 1},
  {0, 1, -1, 0, 0, -1, 1, 0},
  {0, 1, 1, 0, 0, -1, -1, 0},
  {1, 0, 0, 1, -1, 0, 0, -1}
};

void cast_light(Dungeon *dungeon, std::vector<std::vector<bool>> &visible,
                unsigned int x, unsigned int y, unsigned int radius,
                unsigned int row, float start_slope, float end_slope,
                unsigned int xx, unsigned int xy,
                unsigned int yx, unsigned int yy) {
  if (start_slope < end_slope) { return; }
  float next_start_slope = start_slope;
  for (unsigned int i = row; i <= radius; ++i) {
    bool blocked = false;
    for (int dx = -i, dy = -i; dx <= 0; ++dx) {
      float l_slope = (dx - 0.5) / (dy + 0.5);
      float r_slope = (dx + 0.5) / (dy - 0.5);
      if (start_slope < r_slope) {
        continue;
      } else if (end_slope > l_slope) {
        break;
      }

      int sax = dx * xx + dy * xy;
      int say = dx * yx + dy * yy;
      if ((sax < 0 && static_cast<unsigned int>(std::abs((float)sax)) > x) ||
          (say < 0 && static_cast<unsigned int>(std::abs((float)say)) > y)) {
        continue;
      }
      unsigned int ax = x + sax;
      unsigned int ay = y + say;
      if (ax >= dungeon->width() || ay >= dungeon->height()) {
        continue;
      }

      unsigned int radius2 = radius * radius;
      if (static_cast<unsigned int>(dx * dx + dy * dy) < radius2) {
        visible[ax][ay] = true;
      }

      if (blocked) {
        if (dungeon->tile_at(ax, ay)->passable() == false) {
          next_start_slope = r_slope;
          continue;
        } else {
          blocked = false;
          start_slope = next_start_slope;
        }
      } else if (dungeon->tile_at(ax, ay)->passable() == false) {
        blocked = true;
        next_start_slope = r_slope;
        cast_light(dungeon, visible, x, y, radius, i + 1, start_slope,
                   l_slope, xx, xy, yx, yy);
      }
    }

    if (blocked == true) { break; }
  }
}

bool FieldOfView::visible(unsigned int x, unsigned int y) const {
  if (x < visible_.size() && y < visible_[x].size()) {
    return visible_[x][y];
  }

  return false;
}

void FieldOfView::calculate(Dungeon *dungeon, unsigned int x, unsigned int y) {
  visible_.clear();
  visible_.resize(dungeon->width(), std::vector<bool>(dungeon->height(), false));
  for (unsigned int i = 0; i < 8; ++i) {
    cast_light(dungeon, visible_, x, y, radius_, 1, 1.0, 0.0, multipliers[0][i],
               multipliers[1][i], multipliers[2][i], multipliers[3][i]);
  }

  visible_[x][y] = true;
}
