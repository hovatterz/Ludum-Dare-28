#ifndef LD28_PLAYING_CONTROLLER_H_
#define LD28_PLAYING_CONTROLLER_H_

#include <entityx/entityx.h>

#include "controller.h"
#include "game.h"
#include "announcements_receiver.h"
#include "announcements_view.h"
#include "game_view.h"
#include "hud_view.h"

class PlayingController : public Controller {
 public:
  PlayingController(Game *game);

  void update();
  bool handle_event(const tb_event &event);

 private:
  bool waiting_for_player_;
  AnnouncementsReceiver announcements_receiver_;
  Game *game_;
  AnnouncementsView *announcements_view_;
  GameView *game_view_;
  HUDView *hud_view_;

  void on_enter_();
};

#endif  // LD28_PLAYING_CONTROLLER_H_
