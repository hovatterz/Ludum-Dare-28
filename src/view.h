#ifndef LD28_VIEW_H_
#define LD28_VIEW_H_

class View {
 public:
  View(int x, int y, int width, int height);
  virtual ~View();

  virtual void render() = 0;

  int height() const;
  int width() const;
  int x() const;
  int y() const;

 protected:
  int x_, y_, width_, height_;
};

#endif  // LD28_VIEW_H_
