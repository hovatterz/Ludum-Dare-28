#ifndef LD28_TILE_H_
#define LD28_TILE_H_

class Tile {
 public:
  Tile();

  bool passable() const;
  void set_passable(bool passable);

  char symbol() const;
  void set_symbol(char symbol);

  uint16_t foreground() const;
  void set_foreground(uint16_t foreground);

  uint16_t background() const;
  void set_background(uint16_t background);

 private:
  bool passable_;
  char symbol_;
  uint16_t foreground_, background_;
};

#endif  // LD28_TILE_H_
