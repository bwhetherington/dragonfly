#include "time.hpp"

using namespace df;

#if _WIN32 || _WIN64
// Windows specific code

#include <Windows.h>

Time df::microTime() {
  SYSTEMTIME time;
  GetSystemTime(&time);
  return (time.wMinute * 60 * 1000000) + (time.wSecond * 1000000) +
         (time.wMilliseconds * 1000);
}

#elif __APPLE__
// MacOS specific code

#include <sys/time.h>

Time df::microTime() {
  struct timeval time;
  gettimeofday(&time, NULL);
  return time.tv_sec * 1000000 + time.tv_usec;
}

#elif __linux__
// Linux specific code

#include <time.h>

Time df::microTime() {
  struct timespec time;
  clock_gettime(CLOCK_REALTIME, &time);
  return time.tv_sec * 1000000 + time.tv_nsec / 1000;
}

#endif

// inline Time df::time::fromSeconds(int seconds) { return seconds * 1000000; }

// inline Time df::time::fromMilli(int milli) { return milli * 1000; }

// inline Time df::time::fromMicro(int micro) { return micro; }

// inline Time df::time::fromNano(int nano) { return nano / 1000; }