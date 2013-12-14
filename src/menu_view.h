#ifndef LD28_MENU_VIEW_H_
#define LD28_MENU_VIEW_H_

#include <list>
#include <string>

#include "view.h"

class MenuView : public View {
 public:
  MenuView(int x, int y);

  void add_item(const std::string &item);
  int selected() const;
  void set_selected(int selected_index);
  int num_items() const;
  void render();

 private:
  int selected_index_;
  std::list<std::string> items_;
};

#endif  // LD28_MENU_VIEW_H_
