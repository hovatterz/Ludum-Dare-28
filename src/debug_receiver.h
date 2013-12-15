#ifndef LD28_DEBUG_RECEIVER_H_
#define LD28_DEBUG_RECEIVER_H_

#include <entityx/entityx.h>

#include "events.h"

class DebugReceiver : public entityx::Receiver<DebugReceiver> {
 public:
  static entityx::ptr<DebugReceiver> make();

  void configure(entityx::ptr<entityx::EventManager> events);

  void receive(const AttackEvent &event);

 private:
  void Log(const std::string &message);
};

#endif  // LD28_DEBUG_RECEIVER_H_
