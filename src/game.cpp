#include "movement_system.h"
#include "turn_system.h"
#include "rng.h"
#include "script.h"
#include "spatial.h"

#include "game.h"

Game::Game()
  : playing_(false),
    running_(true),
    events_(entityx::EventManager::make()),
    entities_(entityx::EntityManager::make(events_)),
    systems_(entityx::SystemManager::make(entities_, events_)),
    entity_factory_(entities_) {
    }

bool Game::running() const {
  return running_;
}

void Game::start() {
  entities_->destroy_all();

  dungeon_.generate(1, 100, 100);

  player_ = entity_factory_.create_player();
  bool player_placed = false;
  while (player_placed == false) {
    int pos_x = rand_range(0, 100 - 1);
    int pos_y = rand_range(0, 100 - 1);
    if (dungeon_.tile_at(pos_x, pos_y)->passable() == true) {
      player_.component<Spatial>()->set_position(pos_x, pos_y);
      player_placed = true;
    }
  }

  for (int i = 0; i < 50; ++i) {
    bool goblin_placed = false;
    while (goblin_placed == false) {
      int pos_x = rand_range(0, 100 - 1);
      int pos_y = rand_range(0, 100 - 1);
      if (dungeon_.tile_at(pos_x, pos_y)->passable() == true) {
        auto goblin = entity_factory_.create_goblin();
        goblin.component<Spatial>()->set_position(pos_x, pos_y);
        goblin_placed = true;
      }
    }
  }

  for (auto entity : entities_->entities_with_components<Script>()) {
    auto script = entity.component<Script>();
    script->initialize(entity, &dungeon_);
  }

  systems_->add<TurnSystem>();
  systems_->add<MovementSystem>();
  systems_->configure();

  playing_ = true;
}

void Game::step() {
  if (playing_ == true) {
    systems_->update<TurnSystem>(1.0f);
    systems_->update<MovementSystem>(1.0f);
  }
}

void Game::quit() {
  playing_ = false;
  running_ = false;
}

Dungeon *Game::dungeon() {
  return &dungeon_;
}

entityx::Entity Game::player() {
  return player_;
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
