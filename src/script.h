#ifndef LD28_SCRIPT_H_
#define LD28_SCRIPT_H_

#include <string>

#include <entityx/entityx.h>

extern "C" {
  struct lua_State;
}

class Dungeon;

class Script : public entityx::Component<Script> {
 public:
  Script();
  Script(const std::string &file_path);
  ~Script();

  static entityx::ptr<Script> make(const std::string &file_path);

  void initialize(entityx::Entity self, Dungeon *dungeon);
  void think();

 private:
  std::string file_path_;
  lua_State *lua_;
};

#endif  // LD28_SCRIPT_H_
