#include "aspect.h"
#include "spatial.h"

#include "entity_factory.h"

EntityFactory::EntityFactory(entityx::ptr<entityx::EntityManager> entities)
  : entities_(entities) {
  }

entityx::Entity EntityFactory::create_player() {
  entityx::Entity player = entities_->create();
  player.assign<Aspect>(Aspect::make('@', TB_WHITE | TB_BOLD, TB_BLACK));
  player.assign<Spatial>(Spatial::make());
  return player;
}
