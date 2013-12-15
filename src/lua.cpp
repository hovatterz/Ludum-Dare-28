extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "turn_taker.h"

extern int dungeon_register(lua_State *L);
extern int spatial_register(lua_State *L);
extern int tile_register(lua_State *L);
extern int turn_taker_register(lua_State *L);
extern void enum_register(lua_State *L, const char *name, ...);

int luaopen_ld28(lua_State *L) {
  enum_register(L, "action",
                "none", kActionNone,
                "move_north", kActionMoveNorth,
                "move_west", kActionMoveWest,
                "move_south", kActionMoveSouth,
                "move_east", kActionMoveEast,
                "move_northwest", kActionMoveNorthwest,
                "move_northeast", kActionMoveNortheast,
                "move_southwest", kActionMoveSouthwest,
                "move_southeast", kActionMoveSoutheast,
                "\0");

  dungeon_register(L);
  spatial_register(L);
  tile_register(L);
  turn_taker_register(L);
  return 1;
}
