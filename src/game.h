#ifndef LD28_GAME_H_
#define LD28_GAME_H_

class Game {
 public:
  Game();

  bool running() const;
  void quit();

 private:
  bool running_;
};

#endif  // LD28_GAME_H_
