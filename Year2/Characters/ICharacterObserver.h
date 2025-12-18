#pragma once

#include <string>
#include "../Logging/LogLevel.h"

class ICharacter;

class ICharacterObserver {
public:
    virtual ~ICharacterObserver() = default;
    virtual void onAction(const std::string& action, LogLevel level) = 0;
};
