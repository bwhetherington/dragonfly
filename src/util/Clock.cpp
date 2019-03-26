#include "Clock.hpp"
#include "time.hpp"

using namespace df;

Clock::Clock() { m_previous = microTime(); }

Time Clock::delta() {
  Time prev = m_previous;
  m_previous = microTime();
  return prev;
}

Time Clock::split() const { return microTime() - m_previous; }