#include "aspect.h"

Aspect::Aspect() : symbol_('?'), foreground_(TB_WHITE), background_(TB_BLACK) {}

Aspect::Aspect(char symbol, uint16_t foreground, uint16_t background)
  : symbol_(symbol),
    foreground_(foreground),
    background_(background) {
  }

entityx::ptr<Aspect> Aspect::make(char symbol, uint16_t foreground, uint16_t background) {
  return entityx::ptr<Aspect>(new Aspect(symbol, foreground, background));
}

char Aspect::symbol() const {
  return symbol_;
}

void Aspect::set_symbol(char symbol) {
  symbol_ = symbol;
}

uint16_t Aspect::foreground() const {
  return foreground_;
}

void Aspect::set_foreground(uint16_t foreground) {
  foreground_ = foreground;
}

uint16_t Aspect::background() const {
  return background_;
}

void Aspect::set_background(uint16_t background) {
  background_ = background;
}
