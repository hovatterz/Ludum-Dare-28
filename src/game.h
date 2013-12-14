#ifndef LD28_GAME_H_
#define LD28_GAME_H_

#include <entityx/entityx.h>

#include "dungeon.h"

class Game {
 public:
  Game();

  bool running() const;
  void start();
  void quit();

  Dungeon *dungeon();
  entityx::ptr<entityx::EventManager> events();
  entityx::ptr<entityx::EntityManager> entities();
  entityx::ptr<entityx::SystemManager> systems();

 private:
  bool running_;
  Dungeon dungeon_;
  entityx::ptr<entityx::EventManager> events_;
  entityx::ptr<entityx::EntityManager> entities_;
  entityx::ptr<entityx::SystemManager> systems_;
};

#endif  // LD28_GAME_H_
