#ifndef LD28_ANNOUNCEMENTS_VIEW_H_
#define LD28_ANNOUNCEMENTS_VIEW_H_

#include <string>
#include <vector>

#include "announcements_receiver.h"
#include "view.h"

class AnnouncementsView : public View {
 public:
  AnnouncementsView(int x, int y, int width, int height,
                    AnnouncementsReceiver *receiver);

  void render();

 private:
  AnnouncementsReceiver *receiver_;
};

#endif  // LD28_ANNOUNCEMENTS_VIEW_H_

