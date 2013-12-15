extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <sstream>

bool enum_check_type(lua_State *L, const char *name, int index) {
  lua_pushstring(L, "type");
  lua_gettable(L, index - 1);
  if (!lua_isnil(L, -1)) {
    const char *type = lua_tostring(L, -1);
    if (std::strcmp(type, name) == 0) {
      lua_pop(L, 1);
      return true;
    }
  }

  lua_pop(L, 1);
  return false;
}

int enum_get_value(lua_State *L, int index) {
  lua_pushstring(L, "value");
  lua_gettable(L, index - 1);
  return luaL_checkint(L, -1);
}

void enum_register(lua_State *L, const char *name, ...) {
  // NOTE: Here's the Lua code we're building and executing to define the
  //       enum.
  //
  // <tname> = setmetatable( {}, { 
  //      __index = { 
  //          <name1> = { 
  //              value = <value1>, 
  //              type = \"<tname>\"
  //          }, 
  //          ... 
  //      },
  //      __newindex = function(table, key, value)
  //          error(\"Attempt to modify read-only table\")
  //      end,
  //      __metatable = false
  // });

  va_list args;
  std::stringstream code;
  char* ename;
  int evalue;

  code << name << " = setmetatable({}, {";
  code << "__index = {";

  // Iterate over the variadic arguments adding the enum values.
  va_start(args, name);
  while (std::strcmp(ename = va_arg(args, char *), "\0") != 0) {
    evalue = va_arg(args, int);
    code << ename << "={value=" << evalue << ",type=\"" << name << "\"},";
  }
  va_end(args);

  code << "},";
  code << "__newindex = function(table, key, value) error(\"Attempt to modify read-only table\") end,";
  code << "__metatable = false});";

  // Execute lua code
  if (luaL_loadbuffer(L, code.str().c_str(), code.str().length(), 0) || lua_pcall(L, 0, 0, 0)) {
    fprintf(stderr, "%s\n", lua_tostring(L, -1));
    lua_pop(L, 1);
  }
}
