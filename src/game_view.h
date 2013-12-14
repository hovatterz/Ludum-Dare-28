#ifndef LD28_GAME_VIEW_H_
#define LD28_GAME_VIEW_H_

#include "view.h"

class GameView : public View {
 public:
  GameView(int x, int y);

  void render();
};

#endif  // LD28_GAME_VIEW_H_
