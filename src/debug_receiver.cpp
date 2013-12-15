#include <iostream>

#include "debug_receiver.h"

entityx::ptr<DebugReceiver> DebugReceiver::make() {
  return entityx::ptr<DebugReceiver>(new DebugReceiver());
}

void DebugReceiver::configure(entityx::ptr<entityx::EventManager> events) {
  events->subscribe<AttackEvent>(*this);
}

void DebugReceiver::receive(const AttackEvent &event) {
  this->Log("Entity " + std::to_string(event.attacker->id().id())
            + " attacks entity " + std::to_string(event.defender->id().id())
            + " for " + std::to_string(event.damage) + " damage.");
}

void DebugReceiver::Log(const std::string &message) {
  std::cerr << "[Debug] " << message << std::endl;
}
