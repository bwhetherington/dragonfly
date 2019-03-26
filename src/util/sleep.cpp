#include "sleep.hpp"

using namespace df;

void df::milliSleep(int ms) { microSleep(ms * 1000); }

#if _WIN32 || WIN64

#include <Windows.h>

void df::microSleep(int microseconds) { Sleep(microseconds / 1000); }

#elif __APPLE__ || __linux__

#include <time.h>

void df::microSleep(int microseconds) {
  struct timespec time;
  time.tv_sec = 0;
  time.tv_nsec = microseconds * 1000;
  nanosleep(&time, NULL);
}

#endif