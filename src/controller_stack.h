#ifndef LD28_CONTROLLER_STACK_H_
#define LD28_CONTROLLER_STACK_H_

#include <list>

class Controller;

class ControllerStack {
 public:
  ~ControllerStack();

  void change(Controller *controller);
  void push(Controller *controller);
  void pop();

  const std::list<Controller *> &controllers();

 private:
  std::list<Controller *> controllers_;
};

#endif  // LD28_CONTROLLER_STACK_H_
