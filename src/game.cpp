#include "game.h"

Game::Game() : running_(true) {}

bool Game::running() const {
  return running_;
}

void Game::quit() {
  running_ = false;
}
