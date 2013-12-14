#ifndef LD28_VIEW_H_
#define LD28_VIEW_H_

class View {
 public:
  View(int x, int y);
  virtual ~View();

  virtual void render() = 0;

 protected:
  int x_, y_;
};

#endif  // LD28_VIEW_H_
