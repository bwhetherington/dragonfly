#pragma once

#include "time.hpp"

namespace df {

class Clock {
 public:
  // Constructs a default `Clock`.
  Clock();

  // Produces the time since `Clock::delta()` was last called. The units are in
  // microseconds.
  Time delta();

  // Produces the time since `Clock::delta()` was last called. The units are in
  // microseconds.
  Time split() const;

 private:
  // The most recent time that `Clock::delta()` was called.
  Time m_previous;
};

}