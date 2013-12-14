#include <termbox.h>

#include "game_view.h"

#include "playing_controller.h"

PlayingController::PlayingController(Game *game) : game_(game) {}

static int cx = 0;
static int cy = 0;

bool PlayingController::handle_event(const tb_event &event) {
  char input = static_cast<char>(event.ch);
  if (input == 'q') {
    game_->quit();
  } else if (input == 'h') {
    --cx;
    game_view_->set_center(cx, cy);
  } else if (input == 'j') {
    ++cy;
    game_view_->set_center(cx, cy);
  } else if (input == 'k') {
    --cy;
    game_view_->set_center(cx, cy);
  } else if (input == 'l') {
    ++cx;
    game_view_->set_center(cx, cy);
  }

  return false;
}

void PlayingController::on_enter_() {
  game_->start();

  game_view_ = new GameView(0, 0, 50, 20, game_);
  views_.push_back(game_view_);
}
