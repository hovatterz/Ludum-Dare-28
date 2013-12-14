#include <iostream>

#include <entityx/entityx.h>
#include <termbox.h>

#include "debug_receiver.h"
#include "termbox_helpers.h"

int main() {
  int tb_ret = tb_init();
  if (tb_ret != 0) {
    std::cerr << "Failed to initialize termbox (" << tb_ret << ")" << std::endl;
    return 1;
  }

  tb_set_clear_attributes(TB_WHITE, TB_BLACK);

  auto events = entityx::EventManager::make();
  auto entities = entityx::EntityManager::make(events);
  auto systems = entityx::SystemManager::make(entities, events);

  auto debug_receiver = DebugReceiver::make();
  debug_receiver->configure(events);

  bool running = true;
  while (running) {
    struct tb_event event;
    if (tb_peek_event(&event, 0)) {
      if (event.type == TB_EVENT_KEY) {
        char input = static_cast<char>(event.ch);
        if (input == 'q') {
          running = false;
        }
      }
    }

    tb_clear();
    tb_present();
  }

  tb_shutdown();

  return 0;
}
