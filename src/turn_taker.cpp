#include "turn_taker.h"

TurnTaker::TurnTaker() : action_(kActionNone) {}

entityx::ptr<TurnTaker> TurnTaker::make() {
  return entityx::ptr<TurnTaker>(new TurnTaker());
}

Action TurnTaker::action() const {
  return action_;
}

void TurnTaker::set_action(Action action) {
  action_ = action;
}
