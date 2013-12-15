extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <cassert>

#include "turn_taker.h"

extern bool enum_check_type(lua_State *L, const char *name, int index);
extern int enum_get_value(lua_State *L, int index);

namespace {
inline TurnTaker *userdata_to_turn_taker(lua_State *L, int index) {
  void *ud = luaL_checkudata(L, index, "TurnTaker");
  TurnTaker *turn_taker = *((TurnTaker **)ud);
  return turn_taker;
}
}  // anonymous namespace

static int turn_taker_set_action(lua_State *L) {
  assert(lua_gettop(L) == 2);
  TurnTaker *turn_taker = userdata_to_turn_taker(L, 1);
  if (enum_check_type(L, "action", -1) == false) {
    std::cerr << "set_action called with a non-action" << std::endl;
    return 2;
  }

  Action action = static_cast<Action>(enum_get_value(L, -1));
  turn_taker->set_action(action);
  return 1;
}

int turn_taker_register(lua_State *L) {
  luaL_newmetatable(L, "TurnTaker");
  lua_pushvalue(L, -1);
  lua_setfield(L, -2, "__index");

  lua_pushcfunction(L, turn_taker_set_action);
  lua_setfield(L, -2, "set_action");

  return 1;
}

void turn_taker_push(lua_State *L, const char *name, TurnTaker *turn_taker) {
  TurnTaker **ud = (TurnTaker **)lua_newuserdata(L, sizeof(TurnTaker *));
  *(ud) = turn_taker;
  luaL_setmetatable(L, "TurnTaker");
  lua_setglobal(L, name);
};
