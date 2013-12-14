#include <termbox.h>

#include "tile.h"

Tile::Tile() : passable_(true), symbol_('?'), foreground_(TB_WHITE), background_(TB_BLACK) {
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
