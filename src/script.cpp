extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "dungeon.h"

#include "script.h"

extern int dungeon_register(lua_State *L);
extern void dungeon_push(lua_State *L, const char *name, Dungeon *dungeon);

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

void Script::initialize(Dungeon *dungeon) {
  lua_ = luaL_newstate();
  luaL_openlibs(lua_);

  dungeon_register(lua_);
  dungeon_push(lua_, "dungeon", dungeon);

  if (luaL_dofile(lua_, file_path_.c_str()) != 0) {
    std::cerr << "Error running script '" << file_path_ <<
        "': " << lua_tostring(lua_, -1) << std::endl;
  }
}
