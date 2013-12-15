extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "dungeon.h"
#include "spatial.h"
#include "turn_taker.h"

#include "script.h"

extern bool enum_check_type(lua_State *L, const char *name, int index);
extern int enum_get_value(lua_State *L, int index);
extern int luaopen_ld28(lua_State *L);
extern void dungeon_push(lua_State *L, const char *name, Dungeon *dungeon);
extern void spatial_push(lua_State *L, const char *name, Spatial *spatial);
extern void turn_taker_push(lua_State *L, const char *name, TurnTaker *turn_taker);

static void lua_script_think(lua_State *L) {
  lua_getglobal(L, "think");
  if (lua_pcall(L, 0, 0, 0) != 0) {
    std::cerr << "Error running function 'think': " << lua_tostring(L, -1) << std::endl;
  }
}

Script::Script() : file_path_(""), lua_(nullptr) {}
Script::Script(const std::string &file_path) : file_path_(file_path), lua_(nullptr) {}
Script::~Script() {
  if (lua_ != nullptr) {
    lua_close(lua_);
  }
}

entityx::ptr<Script> Script::make(const std::string &file_path) {
  return entityx::ptr<Script>(new Script(file_path));
}

void Script::initialize(entityx::Entity self, Dungeon *dungeon) {
  lua_ = luaL_newstate();
  luaL_openlibs(lua_);

  luaopen_ld28(lua_);
  dungeon_push(lua_, "dungeon", dungeon);
  spatial_push(lua_, "spatial", self.component<Spatial>().get());
  turn_taker_push(lua_, "turn_taker", self.component<TurnTaker>().get());

  if (luaL_dofile(lua_, file_path_.c_str()) != 0) {
    std::cerr << "Error running script '" << file_path_ <<
        "': " << lua_tostring(lua_, -1) << std::endl;
  }
}

void Script::think() {
  lua_script_think(lua_);
}
