#pragma once

#include "ILogger.h"
#include "LogLevel.h"


class ConsoleLogger : public ILogger {
public:
    ~ConsoleLogger() override = default;
    void log(LogLevel level, const std::string& message) override;
};
