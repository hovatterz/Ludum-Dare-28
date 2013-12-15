extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

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

int dungeon_register(lua_State *L) {
  luaL_newmetatable(L, "Dungeon");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, dungeon_width);  lua_setfield(L, -2, "width");
  lua_pushcfunction(L, dungeon_height); lua_setfield(L, -2, "height");

  return 1;
}

void dungeon_push(lua_State *L, const char *name, Dungeon *dungeon) {
  Dungeon **ud = (Dungeon **)lua_newuserdata(L, sizeof(dungeon));
  *(ud) = dungeon;
  luaL_setmetatable(L, "Dungeon");
  lua_setglobal(L, name);
};
