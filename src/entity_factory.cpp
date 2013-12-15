#include "aspect.h"
#include "script.h"
#include "spatial.h"
#include "turn_taker.h"

#include "entity_factory.h"

EntityFactory::EntityFactory(entityx::ptr<entityx::EntityManager> entities)
  : entities_(entities) {
  }

entityx::Entity EntityFactory::create_player() {
  entityx::Entity player = entities_->create();
  player.assign<Aspect>(Aspect::make('@', TB_WHITE | TB_BOLD, TB_BLACK));
  player.assign<Spatial>(Spatial::make());
  player.assign<TurnTaker>(TurnTaker::make());
  return player;
}

entityx::Entity EntityFactory::create_goblin() {
  entityx::Entity goblin = entities_->create();
  goblin.assign<Aspect>(Aspect::make('g', TB_GREEN, TB_BLACK));
  goblin.assign<Spatial>(Spatial::make());
  goblin.assign<Script>(Script::make("scripts/goblin.lua"));
  goblin.assign<TurnTaker>(TurnTaker::make());
  return goblin;
}
