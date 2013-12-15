#ifndef LD28_ANNOUNCEMENTS_VIEW_H_
#define LD28_ANNOUNCEMENTS_VIEW_H_

#include <string>
#include <vector>

#include "view.h"

class AnnouncementsView : public View {
 public:
  AnnouncementsView(int x, int y, int width, int height);

  void add_announcement(const std::string &string);
  void render();

 private:
  std::vector<std::string> announcements_;
};

#endif  // LD28_ANNOUNCEMENTS_VIEW_H_

