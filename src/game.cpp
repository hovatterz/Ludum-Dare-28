#include "game.h"

Game::Game() : running_(true) {}

bool Game::running() const {
  return running_;
}

void Game::start() {
  dungeon_.generate(1, 100, 100);
}

void Game::quit() {
  running_ = false;
}

Dungeon *Game::dungeon() {
  return &dungeon_;
}
