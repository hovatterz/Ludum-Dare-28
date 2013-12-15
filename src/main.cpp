#include <iostream>

#include <termbox.h>

#include "controller_stack.h"
#include "debug_receiver.h"
#include "game.h"
#include "main_menu_controller.h"

int main() {
  std::srand(std::time(nullptr));

  int tb_ret = tb_init();
  if (tb_ret != 0) {
    std::cerr << "Failed to initialize termbox (" << tb_ret << ")" << std::endl;
    return 1;
  }

  tb_set_clear_attributes(TB_WHITE, TB_BLACK);

  Game game;

  auto debug_receiver = DebugReceiver::make();
  debug_receiver->configure(game.events());

  ControllerStack controller_stack;
  controller_stack.push(new MainMenuController(&game));

  while (game.running()) {
    auto &controllers = controller_stack.controllers();

    struct tb_event event;
    if (tb_peek_event(&event, 0)) {
      if (event.type == TB_EVENT_KEY) {
        auto iter = controllers.rbegin();
        for (; iter != controllers.rend(); ++iter) {
          if ((*iter)->handle_event(event) == false) {
            break;
          }
        }
      }
    }

    for (auto controller : controllers) {
      controller->update();
    }

    tb_clear();
    for (auto controller : controllers) {
      controller->display();
    }
    tb_present();
  }

  tb_shutdown();

  return 0;
}
