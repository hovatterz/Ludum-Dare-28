extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "spatial.h"

namespace {
inline Spatial *userdata_to_spatial(lua_State *L, int index) {
  void *ud = luaL_checkudata(L, index, "Spatial");
  Spatial *spatial = *((Spatial **)ud);
  return spatial;
}
}  // anonymous namespace

static int spatial_x(lua_State *L) {
  Spatial *spatial = userdata_to_spatial(L, 1);
  lua_pushinteger(L, spatial->x());
  return 1;
}

static int spatial_y(lua_State *L) {
  Spatial *spatial = userdata_to_spatial(L, 1);
  lua_pushinteger(L, spatial->y());
  return 1;
}

int spatial_register(lua_State *L) {
  luaL_newmetatable(L, "Spatial");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");
  lua_pushcfunction(L, spatial_x);  lua_setfield(L, -2, "x");
  lua_pushcfunction(L, spatial_y);  lua_setfield(L, -2, "y");
  return 1;
}

void spatial_push(lua_State *L, const char *name, Spatial *spatial) {
  Spatial **ud = (Spatial **)lua_newuserdata(L, sizeof(Spatial *));
  *(ud) = spatial;
  luaL_setmetatable(L, "Spatial");
  lua_setglobal(L, name);
};
