#pragma once

#include <string>

enum class LogLevel { ERROR, ACTION, INFO, WARNING };

inline std::string LogLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::ACTION: return "ACTION";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        default: return "UNKNOWN";
    }
}
