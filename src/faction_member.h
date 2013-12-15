#ifndef LD28_FACTION_MEMBER_H_
#define LD28_FACTION_MEMBER_H_

#include <entityx/entityx.h>

typedef enum {
  kFactionNone,
  kFactionPlayer,
  kFactionEverythingElse
} Faction;

class FactionMember : public entityx::Component<FactionMember> {
 public:
  FactionMember();
  FactionMember(Faction faction);
  static entityx::ptr<FactionMember> make(Faction faction);

  Faction faction() const;

 private:
  Faction faction_;
};

#endif  // LD28_FACTION_MEMBER_H_
