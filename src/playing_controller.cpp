#include <termbox.h>

#include "spatial.h"
#include "game_view.h"

#include "playing_controller.h"

PlayingController::PlayingController(Game *game)
  : waiting_for_player_(true),
    game_(game) {
}


void PlayingController::update() {
  if (waiting_for_player_ == false) {
    game_->step();
    waiting_for_player_ = true;
  }
}

static int cx = 0;
static int cy = 0;

bool PlayingController::handle_event(const tb_event &event) {
  char input = static_cast<char>(event.ch);
  if (input == 'q') {
    game_->quit();
  } else if (input == 'h') {
    --cx;
    game_->player().component<Spatial>()->offset_position(-1, 0);
    game_view_->set_center(cx, cy);
  } else if (input == 'j') {
    ++cy;
    game_->player().component<Spatial>()->offset_position(0, 1);
    game_view_->set_center(cx, cy);
  } else if (input == 'k') {
    --cy;
    game_->player().component<Spatial>()->offset_position(0, -1);
    game_view_->set_center(cx, cy);
  } else if (input == 'l') {
    ++cx;
    game_->player().component<Spatial>()->offset_position(1, 0);
    game_view_->set_center(cx, cy);
  } else if (input == 'y') {
    --cx; --cy;
    game_->player().component<Spatial>()->offset_position(-1, -1);
    game_view_->set_center(cx, cy);
  } else if (input == 'u') {
    ++cx; --cy;
    game_->player().component<Spatial>()->offset_position(1, -1);
    game_view_->set_center(cx, cy);
  } else if (input == 'b') {
    --cx; ++cy;
    game_->player().component<Spatial>()->offset_position(-1, 1);
    game_view_->set_center(cx, cy);
  } else if (input == 'n') {
    ++cx; ++cy;
    game_->player().component<Spatial>()->offset_position(1, 1);
    game_view_->set_center(cx, cy);
  }

  waiting_for_player_ = false;
  return false;
}

void PlayingController::on_enter_() {
  game_->start();

  game_view_ = new GameView(0, 0, 50, 20, game_);
  views_.push_back(game_view_);
}
