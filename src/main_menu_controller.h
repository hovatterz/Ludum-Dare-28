#ifndef LD28_MAIN_MENU_CONTROLLER_H_
#define LD28_MAIN_MENU_CONTROLLER_H_

#include "controller.h"

class Game;
class MainMenuController : public Controller {
 public:
  MainMenuController(Game *game);

  void update();
  bool handle_event(const tb_event &event);

 private:
  Game *game_;
  void on_enter_();
};

#endif  // LD28_MAIN_MENU_CONTROLLER_H_
