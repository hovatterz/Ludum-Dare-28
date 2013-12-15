#ifndef LD28_HUD_VIEW_H_
#define LD28_HUD_VIEW_H_

#include "view.h"

class HUDView : public View {
 public:
  HUDView(int x, int y, int width, int height);

  void render();
};

#endif  // LD28_HUD_VIEW_H_
