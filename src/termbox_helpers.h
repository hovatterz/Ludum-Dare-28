#ifndef LD28_TERMBOX_HELPERS_H_
#define LD28_TERMBOX_HELPERS_H_

#include <string>

void tb_draw_string(int x, int y, const std::string &str,
                    uint16_t fg = TB_WHITE, uint16_t bg = TB_BLACK);

void tb_fill(int x, int y, int w, int h, char symbol,
             uint16_t fg = TB_WHITE, uint16_t bg = TB_BLACK);

#endif  // LD28_TERMBOX_HELPERS_H_
