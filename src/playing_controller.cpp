#include <termbox.h>

#include "game_view.h"

#include "playing_controller.h"

PlayingController::PlayingController(Game *game) : game_(game) {}

bool PlayingController::handle_event(const tb_event &event) {
  char input = static_cast<char>(event.ch);
  if (input == 'q') {
    game_->quit();
  }

  return false;
}

void PlayingController::on_enter_() {
  GameView *game_view = new GameView(1, 1);
  views_.push_back(game_view);
}
