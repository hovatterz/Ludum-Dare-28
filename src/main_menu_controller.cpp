#include <termbox.h>

#include "controller_stack.h"
#include "game.h"
#include "menu_view.h"
#include "playing_controller.h"

#include "main_menu_controller.h"

MainMenuController::MainMenuController(Game *game) : game_(game) {}

void MainMenuController::update() {
}

bool MainMenuController::handle_event(const tb_event &event) {
  MenuView *menu = static_cast<MenuView *>(views_.back());

  if (event.ch == 'j') {
    if (menu->selected() < menu->num_items() - 1) {
      menu->set_selected(menu->selected() + 1);
    }
  } else if (event.ch == 'k') {
    if (menu->selected() > 0) {
      menu->set_selected(menu->selected() - 1);
    }
  } else if (event.key == TB_KEY_ENTER) {
    int selected = menu->selected();
    if (selected == 0) {
      controller_stack_->change(new PlayingController(game_));
    } else if (selected == 1) {
      game_->quit();
    }

    menu->set_selected(0);
  }

  return false;
}

void MainMenuController::on_enter_() {
  MenuView *menu = new MenuView(1, 1, 10, 23);
  menu->add_item("Play");
  menu->add_item("Quit");
  views_.push_back(menu);
}
