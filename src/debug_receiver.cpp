#include <iostream>

#include "debug_receiver.h"

entityx::ptr<DebugReceiver> DebugReceiver::make() {
  return entityx::ptr<DebugReceiver>(new DebugReceiver());
}

void DebugReceiver::configure(entityx::ptr<entityx::EventManager> events) {
}

void DebugReceiver::Log(const std::string &message) {
  std::cerr << "[Debug] " << message << std::endl;
}
