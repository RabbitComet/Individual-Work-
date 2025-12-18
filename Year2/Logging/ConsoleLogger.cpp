#include "ConsoleLogger.h"
#include "LogLevel.h"
#include <iostream>

void ConsoleLogger::log(LogLevel level, const std::string& message) {
    std::cout << "[" << LogLevelToString(level) << "]>>" << message << std::endl;
}
