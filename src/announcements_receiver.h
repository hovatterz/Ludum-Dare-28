#ifndef LD28_ANNOUNCEMENTS_RECEIVER_H_
#define LD28_ANNOUNCEMENTS_RECEIVER_H_

#include <string>
#include <vector>

#include <entityx/entityx.h>

#include "events.h"

class AnnouncementsReceiver : public entityx::Receiver<AnnouncementsReceiver> {
 public:
  void configure(entityx::ptr<entityx::EventManager> events);

  const std::vector<std::string> announcements() const;
  void add_announcement(const std::string &message);

  // Event handlers
  void receive(const AttackEvent &event);

 private:
  std::vector<std::string> announcements_;
};

#endif  // LD28_ANNOUNCEMENTS_RECEIVER_H_
