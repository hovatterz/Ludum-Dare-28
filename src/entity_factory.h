#ifndef LD28_ENTITY_FACTORY_H_
#define LD28_ENTITY_FACTORY_H_

#include <string>
#include <entityx/entityx.h>

class EntityFactory {
 public:
  EntityFactory(entityx::ptr<entityx::EntityManager> entities);

  entityx::Entity create_player();

 private:
  entityx::ptr<entityx::EntityManager> entities_;
};

#endif  // LD28_ENTITY_FACTORY_H_
