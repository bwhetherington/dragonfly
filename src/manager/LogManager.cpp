#include "LogManager.hpp"
#include <cstdarg>
#include <cstdio>

using namespace df;

LogManager& LogManager::getInstance() {
  static LogManager manager;
  return manager;
}

LogManager::LogManager() {
  setType("LogManager");
  setLogLevel(INFO);
  setFlush(true);
}

LogManager::~LogManager() {
  // Shut the manager down if it is currently running
  Manager::shutDown();
}

void LogManager::writeTime() const {
  // Only print the time if the manager has started
  if (isStarted()) {
    // Get the current time
    time_t now;
    time(&now);
    struct tm* p_time = localtime(&now);

    // Print the time string
    fprintf(m_log_file, "[%02d:%02d:%02d] ", p_time->tm_hour, p_time->tm_min,
            p_time->tm_sec);
  }
}

void LogManager::writeLogLevel(const LogLevel level) const {
  // Only print the time if the manager has started
  if (isStarted()) {
    // Get the current time

    // Print the time string
    const char* log_str;
    switch (level) {
      case TRACE:
        log_str = "trace";
        break;
      case OFF:
        log_str = "_";
        break;
      case FATAL:
        log_str = "fatal";
        break;
      case ERROR:
        log_str = "error";
        break;
      case WARN:
        log_str = "warn";
        break;
      case INFO:
        log_str = "info";
        break;
    }

    fprintf(m_log_file, "[%s] ", log_str);
  }
}

int LogManager::startUp() {
  Manager::startUp();
  FILE* file = fopen("dragonfly.log", "a");
  m_log_file = file;
  trace("Starting up %s", getType().c_str());
  return 1;
}

void LogManager::shutDown() {
  trace("Shutting down %s", getType().c_str());
  Manager::shutDown();
  fclose(m_log_file);
  m_log_file = nullptr;
}

int LogManager::writeLogArgs(const LogLevel log_level, const char* fmt,
                             va_list args) const {
  if (isStarted() && log_level <= m_log_level) {
    writeLogLevel(log_level);
    writeTime();
    vfprintf(m_log_file, fmt, args);
    fprintf(m_log_file, "\n");
    if (m_do_flush) {
      fflush(m_log_file);
    }
    return 1;
  }
  return 0;
}

int LogManager::writeLog(const LogLevel log_level, const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(log_level, fmt, args);
  va_end(args);
  return res;
}

void LogManager::setFlush(const bool do_flush) { m_do_flush = do_flush; }

void LogManager::setLogLevel(const LogLevel log_level) {
  m_log_level = log_level;
}

int LogManager::info(const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(INFO, fmt, args);
  va_end(args);
  return res;
}

int LogManager::warn(const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(WARN, fmt, args);
  va_end(args);
  return res;
}

int LogManager::error(const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(ERROR, fmt, args);
  va_end(args);
  return res;
}

int LogManager::fatal(const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(FATAL, fmt, args);
  va_end(args);
  return res;
}

int LogManager::trace(const char* fmt, ...) const {
  va_list args;
  va_start(args, fmt);
  int res = writeLogArgs(TRACE, fmt, args);
  va_end(args);
  return res;
}