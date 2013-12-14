#ifndef LD28_GAME_VIEW_H_
#define LD28_GAME_VIEW_H_

#include "game.h"
#include "view.h"

class GameView : public View {
 public:
  GameView(int x, int y, int width, int height, Game *game);

  void set_center(int x, int y);
  void render();

 private:
  int center_x_, center_y_;
  Game *game_;
};

#endif  // LD28_GAME_VIEW_H_
