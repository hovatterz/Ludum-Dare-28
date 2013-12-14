#ifndef LD28_PLAYING_CONTROLLER_H_
#define LD28_PLAYING_CONTROLLER_H_

#include "controller.h"

#include "game.h"

class PlayingController : public Controller {
 public:
  PlayingController(Game *game) : game_(game) { }

  bool handle_event(const tb_event &event) {
    game_->quit();
    return false;
  }

 private:
  Game *game_;
};

#endif  // LD28_PLAYING_CONTROLLER_H_
