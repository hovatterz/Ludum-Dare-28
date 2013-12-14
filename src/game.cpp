#include "game.h"

Game::Game()
  : running_(true),
    events_(entityx::EventManager::make()),
    entities_(entityx::EntityManager::make(events_)),
    systems_(entityx::SystemManager::make(entities_, events_)) {
    }

bool Game::running() const {
  return running_;
}

void Game::start() {
  entities_->destroy_all();
  dungeon_.generate(1, 100, 100);
}

void Game::quit() {
  running_ = false;
}

Dungeon *Game::dungeon() {
  return &dungeon_;
}

entityx::ptr<entityx::EventManager> Game::events() {
  return events_;
}

entityx::ptr<entityx::EntityManager> Game::entities() {
  return entities_;
}

entityx::ptr<entityx::SystemManager> Game::systems() {
  return systems_;
}
