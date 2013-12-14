#include "rect.h"

Rect::Rect(int left, int top, int width, int height) {
  this->set(left, top, width, height);
}

int Rect::left() const {
  return left_;
}

int Rect::top() const {
  return top_;
}

int Rect::width() const {
  return width_;
}

int Rect::height() const {
  return height_;
}

int Rect::center_x() const {
  return center_x_;
}

int Rect::center_y() const {
  return center_y_;
}

void Rect::move(int offset_x, int offset_y) {
  int new_left = left_ + offset_x;
  int new_top = top_ + offset_y;
  this->set(new_left, new_top, width_, height_);
}

void Rect::set(int left, int top, int width, int height) {
  left_ = left;
  top_ = top;
  width_ = width;
  height_ = height;

  center_x_ = (left + width_) * 0.5f;
  center_y_ = (top + height_) * 0.5f;
}
