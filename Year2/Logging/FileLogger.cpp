#include "FileLogger.h"

FileLogger::FileLogger(IWriter* writer)
    : writer(writer) {}

void FileLogger::log(LogLevel level, const std::string& message) {
    if (!writer) return;
    std::string formatted = "[" + LogLevelToString(level) + "]>>" + message;
    writer->write(formatted);
}
