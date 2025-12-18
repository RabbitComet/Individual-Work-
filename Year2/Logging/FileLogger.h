#pragma once

#include "ILogger.h"
#include "IWriter.h"
#include "LogLevel.h"

class FileLogger : public ILogger {
private:
    IWriter* writer;
public:
    explicit FileLogger(IWriter* writer);
    void log(LogLevel level, const std::string& message) override;
    ~FileLogger() override = default;
};
