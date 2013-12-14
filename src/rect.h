#ifndef LD28_RECT_H_
#define LD28_RECT_H_

class Rect {
 public:
  Rect(int left, int top, int width, int height);

  Rect padded(int padding);

  int left() const;
  int top() const;
  int width() const;
  int height() const;
  int center_x() const;
  int center_y() const;
  void move(int offset_x, int offset_y);
  void set(int left, int top, int width, int height);

 private:
  int left_, top_, width_, height_;
  int center_x_, center_y_;
};

#endif  // LD28_RECT_H_
