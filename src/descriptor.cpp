#include "descriptor.h"

Descriptor::Descriptor() : name_("Unknown") {}
Descriptor::Descriptor(const std::string &name) : name_(name) {}
entityx::ptr<Descriptor> Descriptor::make(const std::string &name) {
  return entityx::ptr<Descriptor>(new Descriptor(name));
}

const std::string &Descriptor::name() const {
  return name_;
}
void Descriptor::set_name(const std::string &name) {
  name_ = name;
}
