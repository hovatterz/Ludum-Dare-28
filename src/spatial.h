#ifndef LD28_SPATIAL_H_
#define LD28_SPATIAL_H_

#include <entityx/entityx.h>

class Spatial : public entityx::Component<Spatial> {
 public:
  Spatial();
  Spatial(int x, int y);
  static entityx::ptr<Spatial> make(int x = 0, int y = 0);

  int x() const;
  int y() const;
  void set_position(int x, int y);
  void offset_position(int x, int y);

 private:
  int x_, y_;
};

#endif  // LD28_SPATIAL_H_
