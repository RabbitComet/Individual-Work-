#pragma once

#include "ICharacterObserver.h"
#include "../Logging/ILogger.h"
#include "../Logging/LogLevel.h"
#include <string>

class ConsoleObserver : public ICharacterObserver {
public:
    explicit ConsoleObserver(ILogger* logger);
    void onAction(const std::string& action, LogLevel level) override;

private:
    ILogger* logger;
};
