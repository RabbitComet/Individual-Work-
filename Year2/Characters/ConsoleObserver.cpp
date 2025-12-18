#include "ConsoleObserver.h"

ConsoleObserver::ConsoleObserver(ILogger* logger)
    : logger(logger) {}

void ConsoleObserver::onAction(const std::string& action, LogLevel level) {
    if (logger) logger->log(level, action);
}
