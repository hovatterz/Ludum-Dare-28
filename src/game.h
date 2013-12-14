#ifndef LD28_GAME_H_
#define LD28_GAME_H_

#include "dungeon.h"

class Game {
 public:
  Game();

  bool running() const;
  void start();
  void quit();

  Dungeon *dungeon();

 private:
  bool running_;

  Dungeon dungeon_;
};

#endif  // LD28_GAME_H_
