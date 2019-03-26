#pragma once
#include <string>

namespace df {

class Manager {
 private:
  // Represents the type of the manager.
  std::string m_type;

  // Represents whether or not the manager has started.
  bool m_is_started;

 protected:
  // Sets the type of the manager to the type with the specified name.
  void setType(std::string type);

  // Sets the type of the manager to the type with the specified name.
  void setType(const char* type);

 public:
  Manager();
  virtual ~Manager();

  // Produces the type of the manager.
  std::string getType() const;

  // Starts up the manager.
  virtual int startUp();

  // Shuts down the manager.
  virtual void shutDown();

  bool isStarted() const;
};

};  // namespace df