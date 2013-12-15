#include <termbox.h>

#include "controller_stack.h"
#include "field_of_view.h"
#include "main_menu_controller.h"
#include "script.h"
#include "spatial.h"
#include "turn_taker.h"

#include "playing_controller.h"

PlayingController::PlayingController(Game *game)
  : waiting_for_player_(true),
    game_(game) {
}


void PlayingController::update() {
  if (waiting_for_player_ == false) {
    waiting_for_player_ = true;

    game_->step();

    entityx::Entity player = game_->player();;
    if (player.valid() == false) {
      controller_stack_->change(new MainMenuController(game_));
    } else {
      auto fov = player.component<FieldOfView>();
      auto spatial = player.component<Spatial>();

      fov->calculate(game_->dungeon(), spatial->x(), spatial->y());
      game_view_->set_center(spatial->x(), spatial->y());
    }
  }
}

bool PlayingController::handle_event(const tb_event &event) {
  char input = static_cast<char>(event.ch);

  if (input == 'q') {
    game_->quit();
  } else {
    auto script = game_->player().component<Script>();
    waiting_for_player_ = !script->handle_input(input);
  }

  return false;
}

void PlayingController::on_enter_() {
  game_->start();

  auto player = game_->player();

  game_view_ = new GameView(0, 0, 50, 20, game_);
  game_view_->set_center(player.component<Spatial>()->x(),
                         player.component<Spatial>()->y());
  views_.push_back(game_view_);

  hud_view_ = new HUDView(50, 0, 30, 20, game_);
  views_.push_back(hud_view_);

  announcements_receiver_.configure(game_->events());
  announcements_receiver_.add_announcement("Welcome to LD28 'You Only Get One' Roguelike");

  announcements_view_ = new AnnouncementsView(0, 20, 80, 4, &announcements_receiver_);
  views_.push_back(announcements_view_);
}
