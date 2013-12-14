#ifndef LD28_GAME_VIEW_H_
#define LD28_GAME_VIEW_H_

#include "game.h"
#include "view.h"

class GameView : public View {
 public:
  GameView(int x, int y, Game *game);

  void render();

 private:
  Game *game_;
};

#endif  // LD28_GAME_VIEW_H_
