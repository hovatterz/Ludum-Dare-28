#ifndef LD28_PLAYING_CONTROLLER_H_
#define LD28_PLAYING_CONTROLLER_H_

#include "controller.h"
#include "game.h"
#include "game_view.h"

class PlayingController : public Controller {
 public:
  PlayingController(Game *game);

  bool handle_event(const tb_event &event);

 private:
  Game *game_;
  GameView *game_view_;

  void on_enter_();
};

#endif  // LD28_PLAYING_CONTROLLER_H_
