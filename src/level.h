#ifndef LD28_LEVEL_H_
#define LD28_LEVEL_H_

#include <list>
#include <vector>

#include "rect.h"
#include "tile.h"

#define NUM_ROOMS       50
#define MIN_SIZE        6
#define MAX_SIZE        6
#define MIN_CONNECTIONS 3
#define MAX_CONNECTIONS 4

class Room {
 public:
  explicit Room(const Rect &rect);

  const Rect rect() const;

  const std::list<Room *> &connections() const;
  void add_connection(Room *room);

 private:
  std::list<Room *> connections_;
  Rect rect_;
};

class Level {
 public:
  void generate(int width, int height);

  int height() const;
  int width() const;

  Tile *tile_at(int x, int y);

 private:
  std::vector<std::vector<Tile>> tiles_;
  std::vector<Room> rooms_;

  int width_, height_;
};

#endif  // LD28_LEVEL_H_
