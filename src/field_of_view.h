#ifndef LD28_FIELD_OF_VIEW_H_
#define LD28_FIELD_OF_VIEW_H_

#include <entityx/entity.h>

#include "dungeon.h"

class FieldOfView : public entityx::Component<FieldOfView> {
 public:
  FieldOfView();
  FieldOfView(int radius);
  static entityx::ptr<FieldOfView> make(unsigned int radius);

  bool visible(unsigned int x, unsigned int y) const;
  void calculate(Dungeon *dungeon, unsigned int x, unsigned int y);

 private:
  unsigned int radius_;
  std::vector<std::vector<bool>> visible_;
};

#endif  // LD28_FIELD_OF_VIEW_H_
