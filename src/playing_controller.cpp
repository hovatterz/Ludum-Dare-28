#include <termbox.h>

#include "spatial.h"
#include "turn_taker.h"

#include "playing_controller.h"

PlayingController::PlayingController(Game *game)
  : waiting_for_player_(true),
    game_(game) {
}


void PlayingController::update() {
  if (waiting_for_player_ == false) {
    waiting_for_player_ = true;

    game_->step();

    auto player_spatial = game_->player().component<Spatial>();
    game_view_->set_center(player_spatial->x(), player_spatial->y());
  }
}

bool PlayingController::handle_event(const tb_event &event) {
  char input = static_cast<char>(event.ch);
  auto turn_taker = game_->player().component<TurnTaker>();

  if (input == 'q') {
    game_->quit();
  } else if (input == 'h') {
    turn_taker->set_action(kActionMoveWest);
    waiting_for_player_ = false;
  } else if (input == 'j') {
    turn_taker->set_action(kActionMoveSouth);
    waiting_for_player_ = false;
  } else if (input == 'k') {
    turn_taker->set_action(kActionMoveNorth);
    waiting_for_player_ = false;
  } else if (input == 'l') {
    turn_taker->set_action(kActionMoveEast);
    waiting_for_player_ = false;
  } else if (input == 'y') {
    turn_taker->set_action(kActionMoveNorthwest);
    waiting_for_player_ = false;
  } else if (input == 'u') {
    turn_taker->set_action(kActionMoveNortheast);
    waiting_for_player_ = false;
  } else if (input == 'b') {
    turn_taker->set_action(kActionMoveSouthwest);
    waiting_for_player_ = false;
  } else if (input == 'n') {
    turn_taker->set_action(kActionMoveSoutheast);
    waiting_for_player_ = false;
  } else if (input == '.') {
    turn_taker->set_action(kActionNone);
    waiting_for_player_ = false;
  }

  return false;
}

void PlayingController::on_enter_() {
  game_->start();

  game_view_ = new GameView(0, 0, 50, 20, game_);
  views_.push_back(game_view_);

  hud_view_ = new HUDView(50, 0, 30, 20, game_);
  views_.push_back(hud_view_);

  announcements_receiver_.configure(game_->events());
  announcements_receiver_.add_announcement("Welcome to LD28 'You Only Get One' Roguelike");

  announcements_view_ = new AnnouncementsView(0, 20, 80, 4, &announcements_receiver_);
  views_.push_back(announcements_view_);
}
