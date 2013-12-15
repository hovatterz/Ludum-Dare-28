#ifndef LD28_DESCRIPTOR_H_
#define LD28_DESCRIPTOR_H_

#include <string>

#include <entityx/entityx.h>

class Descriptor : public entityx::Component<Descriptor> {
 public:
  Descriptor();
  Descriptor(const std::string &name);
  static entityx::ptr<Descriptor> make(const std::string &name);

  const std::string &name() const;
  void set_name(const std::string &name);

 private:
  std::string name_;
};

#endif  // LD28_DESCRIPTOR_H_
