#ifndef LD28_ASPECT_H_
#define LD28_ASPECT_H_

#include <termbox.h>

#include <entityx/entityx.h>

class Aspect : public entityx::Component<Aspect> {
 public:
  Aspect();
  Aspect(char symbol, uint16_t foreground, uint16_t background);

  static entityx::ptr<Aspect> make(char symbol = '?',
                                   uint16_t foreground = TB_WHITE,
                                   uint16_t background = TB_BLACK);

  char symbol() const;
  void set_symbol(char symbol);

  uint16_t foreground() const;
  void set_foreground(uint16_t foreground);

  uint16_t background() const;
  void set_background(uint16_t background);

 private:
  char symbol_;
  uint16_t foreground_;
  uint16_t background_;
};

#endif  // LD28_ASPECT_H_
