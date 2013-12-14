#include "controller.h"

Controller::Controller() {}

Controller::~Controller() {
  for (auto view : views_) {
    delete view;
  }
}

void Controller::display() {
  for (auto view : views_) {
    view->render();
  }
}

void Controller::on_enter_() {}

void Controller::on_leave_() {}

void Controller::initialize_(ControllerStack *controller_stack) {
  controller_stack_ = controller_stack;
}
