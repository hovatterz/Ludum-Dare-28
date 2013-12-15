extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <cassert>

#include "dungeon.h"

namespace {
inline Dungeon *userdata_to_dungeon(lua_State *L, int index) {
  void *ud = luaL_checkudata(L, index, "Dungeon");
  Dungeon *dungeon = *((Dungeon **)ud);
  return dungeon;
}
}  // anonymous namespace

static int dungeon_width(lua_State *L) {
  Dungeon *dungeon = userdata_to_dungeon(L, 1);
  lua_pushinteger(L, dungeon->width());
  return 1;
}

static int dungeon_height(lua_State *L) {
  Dungeon *dungeon = userdata_to_dungeon(L, 1);
  lua_pushinteger(L, dungeon->height());
  return 1;
}

static int dungeon_tile_at(lua_State *L) {
  assert(lua_gettop(L) == 3);
  Dungeon *dungeon = userdata_to_dungeon(L, 1);
  int x = luaL_checkint(L, 2);
  int y = luaL_checkint(L, 3);

  Tile **ud = (Tile **)lua_newuserdata(L, sizeof(Tile *));
  *(ud) = dungeon->tile_at(x, y);
  luaL_setmetatable(L, "Tile");
  return 1;
}

int dungeon_register(lua_State *L) {
  luaL_newmetatable(L, "Dungeon");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, dungeon_width);   lua_setfield(L, -2, "width");
  lua_pushcfunction(L, dungeon_height);  lua_setfield(L, -2, "height");
  lua_pushcfunction(L, dungeon_tile_at); lua_setfield(L, -2, "tile_at");
  return 1;
}

void dungeon_push(lua_State *L, const char *name, Dungeon *dungeon) {
  Dungeon **ud = (Dungeon **)lua_newuserdata(L, sizeof(Dungeon *));
  *(ud) = dungeon;
  luaL_setmetatable(L, "Dungeon");
  lua_setglobal(L, name);
};
