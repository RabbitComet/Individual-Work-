#pragma once

#include <string>

class IWriter {
public:
    virtual ~IWriter() = default;
    virtual void write(const std::string& text) = 0;
};
