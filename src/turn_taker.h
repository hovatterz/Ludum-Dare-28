#ifndef LD28_TURN_TAKER_H_
#define LD28_TURN_TAKER_H_

#include <entityx/entityx.h>

typedef enum {
  kActionNone,
  kActionMoveNorth,
  kActionMoveWest,
  kActionMoveSouth,
  kActionMoveEast,
  kActionMoveNorthwest,
  kActionMoveNortheast,
  kActionMoveSouthwest,
  kActionMoveSoutheast
} Action;

class TurnTaker : public entityx::Component<TurnTaker> {
 public:
  TurnTaker();
  static entityx::ptr<TurnTaker> make();

  Action action() const;
  void set_action(Action action);

 private:
  Action action_;
};

#endif  // LD28_TURN_TAKER_H_
