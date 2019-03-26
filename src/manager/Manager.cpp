#include "Manager.hpp"

using namespace df;

Manager::Manager() {
  setType("unknown");
  m_is_started = false;
}

Manager::~Manager() {
  if (isStarted()) {
    shutDown();
  }
}

void Manager::setType(std::string type) { m_type = type; }

void Manager::setType(const char* type) {
  std::string str(type);
  setType(str);
}

std::string Manager::getType() const { return m_type; }

int Manager::startUp() {
  m_is_started = true;
  return 0;
}

void Manager::shutDown() { m_is_started = false; }

bool Manager::isStarted() const { return m_is_started; }