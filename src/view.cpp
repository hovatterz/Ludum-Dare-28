#include "view.h"

View::View(int x, int y, int width, int height)
  : x_(x),
    y_(y),
    width_(width),
    height_(height) {
    }

View::~View() {}

int View::height() const {
  return height_;
}

int View::width() const {
  return width_;
}

int View::x() const {
  return x_;
}

int View::y() const {
  return y_;
}
