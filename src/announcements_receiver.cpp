#include "announcements_receiver.h"

void AnnouncementsReceiver::configure(entityx::ptr<entityx::EventManager> events) {
  events->subscribe<AttackEvent>(*this);
}

const std::vector<std::string> AnnouncementsReceiver::announcements() const {
  return announcements_;
}

void AnnouncementsReceiver::add_announcement(const std::string &message) {
  announcements_.push_back(message);
}

// Event handlers
void AnnouncementsReceiver::receive(const AttackEvent &event) {
  announcements_.push_back(
      "Entity " + std::to_string(event.attacker->id().id())
      + " attacks entity " + std::to_string(event.target->id().id())
      + " for " + std::to_string(event.damage) + " damage.");
}
