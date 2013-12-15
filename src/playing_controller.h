#ifndef LD28_PLAYING_CONTROLLER_H_
#define LD28_PLAYING_CONTROLLER_H_

#include "controller.h"
#include "game.h"
#include "game_view.h"
#include "hud_view.h"

class PlayingController : public Controller {
 public:
  PlayingController(Game *game);

  void update();
  bool handle_event(const tb_event &event);

 private:
  bool waiting_for_player_;
  Game *game_;
  GameView *game_view_;
  HUDView *hud_view_;

  void on_enter_();
};

#endif  // LD28_PLAYING_CONTROLLER_H_
