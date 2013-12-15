#include "descriptor.h"

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
  auto attacker = event.attacker->component<Descriptor>();
  std::string attacker_name;
  if (attacker == nullptr) {
    attacker_name = std::to_string(event.attacker->id().id());
  } else {
    attacker_name = attacker->name();
  }

  auto defender = event.defender->component<Descriptor>();
  std::string defender_name;
  if (defender == nullptr) {
    defender_name = std::to_string(event.defender->id().id());
  } else {
    defender_name = defender->name();
  }

  announcements_.push_back(
      attacker_name + " attacks " + defender_name
      + " for " + std::to_string(event.damage) + " damage.");
}
