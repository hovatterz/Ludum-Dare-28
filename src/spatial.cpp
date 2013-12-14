#include "spatial.h"

Spatial::Spatial() : x_(0), y_(0) {}
Spatial::Spatial(int x, int y) : x_(x), y_(y) {}

entityx::ptr<Spatial> Spatial::make(int x, int y) {
  return entityx::ptr<Spatial>(new Spatial(x, y));
}

int Spatial::x() const {
  return x_;
}

int Spatial::y() const {
  return y_;
}

void Spatial::set_position(int x, int y) {
  x_ = x;
  y_ = y;
}

void Spatial::offset_position(int x, int y) {
  x_ += x;
  y_ += y;
}
