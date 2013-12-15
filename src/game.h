#ifndef LD28_GAME_H_
#define LD28_GAME_H_

#include <entityx/entityx.h>

#include "dungeon.h"
#include "entity_factory.h"

class Game {
 public:
  Game();

  bool running() const;
  bool playing() const;
  void start();
  void step();
  void quit();

  Dungeon *dungeon();
  EntityFactory *entity_factory();
  entityx::Entity player();

  entityx::ptr<entityx::EventManager> events();
  entityx::ptr<entityx::EntityManager> entities();
  entityx::ptr<entityx::SystemManager> systems();

 private:
  bool playing_;
  bool running_;

  entityx::ptr<entityx::EventManager> events_;
  entityx::ptr<entityx::EntityManager> entities_;
  entityx::ptr<entityx::SystemManager> systems_;

  Dungeon dungeon_;
  entityx::Entity player_;
  EntityFactory entity_factory_;
};

#endif  // LD28_GAME_H_
