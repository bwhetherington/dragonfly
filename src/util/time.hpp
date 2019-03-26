#pragma once
#include <cstdint>

namespace df {

// A unit to represent quantities of time.
typedef uint64_t Time;

// Produces the current system time in microseconds.
Time microTime();



namespace time {

inline Time fromSeconds(int seconds) { return seconds * 1000000; }

inline Time fromMilli(int milliseconds) { return milliseconds * 1000; }

inline Time fromMicro(int microseconds) { return microseconds; }

inline Time fromNano(int nanoseconds) { return nanoseconds / 1000; }

}  // namespace time

}  // namespace df