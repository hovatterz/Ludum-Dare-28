#include <termbox.h>

#include "tile.h"

Tile::Tile(TileType type)
  : passable_(true),
    symbol_('?'),
    foreground_(TB_WHITE),
    background_(TB_BLACK) {
      this->set_type(type);
}

bool Tile::passable() const {
  return passable_;
}

void Tile::set_passable(bool passable) {
  passable_ = passable;
}

char Tile::symbol() const {
  return symbol_;
}

void Tile::set_symbol(char symbol) {
  symbol_ = symbol;
}

uint16_t Tile::foreground() const {
  return foreground_;
}

void Tile::set_foreground(uint16_t foreground) {
  foreground_ = foreground;
}

uint16_t Tile::background() const {
  return background_;
}

void Tile::set_background(uint16_t background) {
  background_ = background;
}

TileType Tile::type() const {
  return type_;
}

void Tile::set_type(TileType type) {
  type_ = type;
  switch (type_) {
    case kTileUnknown:
      symbol_ = '?';
      foreground_ = TB_WHITE;
      background_ = TB_BLACK;
      passable_ = false;
      break;

    case kTileFloor:
      symbol_ = '.';
      foreground_ = TB_WHITE;
      background_ = TB_BLACK;
      passable_ = true;
      break;

    case kTileWall:
      symbol_ = '#';
      foreground_ = TB_YELLOW;
      background_ = TB_BLACK;
      passable_ = false;
      break;
  }
}
