#pragma once
#include <cstdarg>
#include "Manager.hpp"

namespace df {

enum LogLevel { OFF = 0, FATAL = 1, ERROR = 2, WARN = 3, INFO = 4, TRACE = 5 };

class LogManager : public Manager {
 private:
  // Block users from constructing their own `LogManager`; provide only the
  // singleton instance.
  LogManager();

  // Block
  LogManager(const LogManager&);

  // Block assignment
  void operator=(const LogManager&);

  // Whether or not the `LogManager` flushes after each log written.
  bool m_do_flush;

  // A file pointer to the `LogManager`'s log file.
  FILE* m_log_file;

  // The maximum `LogLevel` displayed by the `LogManager`.
  LogLevel m_log_level;

  // Writes the current time string to the log file.
  void writeTime() const;

  // Writes the variadic list of arguments as a log with the specified
  // `LogLevel`.
  int writeLogArgs(const LogLevel log_level, const char* fmt,
                   va_list args) const;

  // Writes the log level string to the log file.
  void writeLogLevel(const LogLevel log_level) const;

 public:
  ~LogManager();

  // Produces the singleton instance of `LogManager`.
  static LogManager& getInstance();

  // Starts the `LogManager`, opening its file pointer.
  int startUp() override;

  // Shuts down the `LogManager`, closing its file pointer.
  void shutDown() override;

  // Sets whether or not to flush the `LogManager` after each logging call.
  void setFlush(const bool do_flush);

  // Writes a log with the specified `LogLevel`.
  int writeLog(const LogLevel log_level, const char* fmt, ...) const;

  // Sets the maximum `LogLevel` to display.
  void setLogLevel(const LogLevel log_level);

  // Produces the maximum `LogLevel` displayed by the `LogManager`.
  LogLevel getLogLevel() const;

  // Logs the specified message with a `LogLevel` of `INFO`.
  int info(const char* fmt, ...) const;

  // Logs the specified message with a `LogLevel` of `WARN`.
  int warn(const char* fmt, ...) const;

  // Logs the specified message with a `LogLevel` of `ERROR`.
  int error(const char* fmt, ...) const;

  // Logs the specified message with a `LogLevel` of `FATAL`.
  int fatal(const char* fmt, ...) const;

  // Logs the specified message with a `LogLevel` of `TRACE`.
  int trace(const char* fmt, ...) const;
};

}  // namespace df