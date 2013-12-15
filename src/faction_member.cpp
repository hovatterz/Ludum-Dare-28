#include "faction_member.h"

FactionMember::FactionMember() : faction_(kFactionNone) {}
FactionMember::FactionMember(Faction faction) : faction_(faction) {}
entityx::ptr<FactionMember> FactionMember::make(Faction faction) {
  return entityx::ptr<FactionMember>(new FactionMember(faction));
}

Faction FactionMember::faction() const {
  return faction_;
}
