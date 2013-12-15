extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "tile.h"

namespace {
inline Tile *userdata_to_tile(lua_State *L, int index) {
  void *ud = luaL_checkudata(L, index, "Tile");
  Tile *tile = *((Tile **)ud);
  return tile;
}
}  // anonymous namespace

static int tile_passable(lua_State *L) {
  Tile *tile = userdata_to_tile(L, 1);
  lua_pushboolean(L, tile->passable());
  return 1;
}

int tile_register(lua_State *L) {
  luaL_newmetatable(L, "Tile");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, tile_passable); lua_setfield(L, -2, "passable");
  return 1;
}

void tile_push(lua_State *L, const char *name, Tile *tile) {
  Tile **ud = (Tile **)lua_newuserdata(L, sizeof(Tile *));
  *(ud) = tile;
  luaL_setmetatable(L, "Tile");
  lua_setglobal(L, name);
};
