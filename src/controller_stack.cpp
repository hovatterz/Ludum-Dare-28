#include "controller.h"

#include "controller_stack.h"

ControllerStack::~ControllerStack() {
  while (controllers_.size() > 0) {
    this->pop();
  }
}

void ControllerStack::change(Controller *controller) {
  this->pop();
  this->push(controller);
}

void ControllerStack::push(Controller *controller) {
  controllers_.push_back(controller);
  controller->initialize_(this);
  controller->on_enter_();
}

void ControllerStack::pop() {
  controllers_.back()->on_leave_();
  delete controllers_.back();
  controllers_.pop_back();
}

const std::list<Controller *> &ControllerStack::controllers() {
  return controllers_;
}
