#include <cmath>
#include <algorithm>
#include <utility>

#include <termbox.h>

#include "rng.h"

#include "level.h"

bool nearest_sort(const std::pair<int, Room *> &a,
                  const std::pair<int, Room *> &b) {
  return a.first < b.first;
}

// Returns a list of rooms sorted by distance from the given room
std::vector<std::pair<int, Room *>> find_nearest_rooms(const Room &room, std::vector<Room> &rooms) {
  std::vector<std::pair<int, Room *>> nearest;
  for (auto &other : rooms) {
    int x1 = room.rect().center_x();
    int y1 = room.rect().center_y();
    int x2 = other.rect().center_x();
    int y2 = other.rect().center_y();

    // Don't add the given room to the list
    if (x1 == x2 && y1 == y2) { continue; }

    // Find manhattan distance
    double distance = (std::abs(x1 - x2) + std::abs(y1 - y2));
    nearest.push_back(std::make_pair(distance, &other));
  }

  std::sort(nearest.begin(), nearest.end(), nearest_sort);

  return nearest;
}

bool connect_rooms(Room *a, Room *b, std::vector<std::vector<Tile>> &tiles) {
  auto connections = a->connections();

  auto result = std::find(connections.begin(), connections.end(), b);
  if (result != connections.begin()) {
    // These rooms are already connected
    return false;
  }

  int start_x = std::min(a->rect().center_x(), b->rect().center_x());
  int start_y = std::min(a->rect().center_y(), b->rect().center_y());
  int end_x = std::max(a->rect().center_x(), b->rect().center_x());
  int end_y = std::max(a->rect().center_y(), b->rect().center_y());

  int direction = rand_range(0, 1);
  if (direction == 0) {
    for (int x = start_x; x < end_x; ++x) {
      tiles[x][start_y].set_type(kTileFloor);
    }

    for (int y = start_y; y < end_y; ++y) {
      tiles[end_x][y].set_type(kTileFloor);
    }
  } else {
    for (int x = start_x; x < end_x; ++x) {
      tiles[x][end_y].set_type(kTileFloor);
    }

    for (int y = start_y; y < end_y; ++y) {
      tiles[start_x][y].set_type(kTileFloor);
    }
  }

  a->add_connection(b);
  b->add_connection(a);

  return true;
}

bool is_rect_solid(const std::vector<std::vector<Tile>> &tiles,
                   Rect rect, TileType type) {
  for (int x = rect.left(); x < rect.left() + rect.width(); ++x) {
    for (int y = rect.top(); y < rect.top() + rect.height(); ++y) {
      if (tiles[x][y].type() != type) {
        return false;
      }
    }
  }

  return true;
}

void fill_rect(std::vector<std::vector<Tile>> &tiles_, Rect rect,
               TileType type) {
  for (int x = rect.left(); x < rect.left() + rect.width(); ++x) {
    for (int y = rect.top(); y < rect.top() + rect.height(); ++y) {
      tiles_[x][y].set_type(type);
    }
  }
}

Rect random_room(int level_width, int level_height,
                 int min_width, int min_height,
                 int max_width, int max_height) {
  int w = rand_range(min_width, max_width);
  int h = rand_range(min_height, max_height);
  int x = rand_range(1, level_width - w - 1);
  int y = rand_range(1, level_height - h - 1);
  return Rect(x, y, w, h);
};

Room::Room(const Rect &rect) : rect_(rect) {}

const Rect Room::rect() const {
  return rect_;
}

const std::list<Room *> &Room::connections() const {
  return connections_;
}

void Room::add_connection(Room *room) {
  connections_.push_back(room);
}

void Level::generate(int width, int height) {
  width_ = width;
  height_ = height;

  tiles_.clear();
  tiles_.resize(width_, std::vector<Tile>(height, Tile(kTileWall)));

  // Place rooms
  for (int i = 0; i < NUM_ROOMS; ++i) {
    bool room_placed = false;
    while (!room_placed) {
      Rect rect = random_room(width_, height_, MIN_SIZE, MIN_SIZE, MAX_SIZE, MAX_SIZE);
      if (is_rect_solid(tiles_, rect.padded(1), kTileWall) == true) {
        fill_rect(tiles_, rect, kTileFloor);
        rooms_.push_back(Room(rect));
        room_placed = true;
      }
    }
  }

  // Connect rooms
  for (auto &room : rooms_) {
    int desired_connections = rand_range(MIN_CONNECTIONS, MAX_CONNECTIONS);
    for (int i = 0; i < desired_connections; ++i) {
      bool connection_placed = false;
      while (!connection_placed) {
        auto nearest_rooms = find_nearest_rooms(room, rooms_);
        for (auto other : nearest_rooms) {
          if (connect_rooms(&room, other.second, tiles_)) {
            connection_placed = true;
            break;
          }
        }
      }
    }
  }
}

int Level::height() const {
  return height_;
}

int Level::width() const {
  return width_;
}

Tile *Level::tile_at(int x, int y) {
  if (x >= 0 && x < width_ && y >= 0 && y < height_) {
    return &tiles_[x][y];
  }

  return nullptr;
}
