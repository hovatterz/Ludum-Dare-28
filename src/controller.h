#ifndef LD28_CONTROLLER_H_
#define LD28_CONTROLLER_H_

#include <list>

#include "view.h"

struct tb_event;

class ControllerStack;

class Controller {
 public:
  Controller();
  virtual ~Controller();

  virtual void update() = 0;
  virtual bool handle_event(const tb_event &event) = 0;
  void display();

 protected:
  std::list<View *> views_;
  ControllerStack *controller_stack_;

  virtual void on_enter_();
  virtual void on_leave_();

 private:
  friend class ControllerStack;
  void initialize_(ControllerStack *controller_stack);
};

#endif  // LD28_CONTROLLER_H_
