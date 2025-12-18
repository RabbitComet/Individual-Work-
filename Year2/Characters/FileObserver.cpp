#include "FileObserver.h"

FileObserver::FileObserver(ILogger* logger)
    : logger(logger) {}

void FileObserver::onAction(const std::string& action, LogLevel level) {
    if (logger) logger->log(level, action);
}
