#pragma once

#include "IWriter.h"
#include <fstream>


class FileWriter : public IWriter {
private:
    std::fstream file;
public:
    FileWriter() = delete;
    explicit FileWriter(const std::string& fileName);
    void write(const std::string& text) override;
    ~FileWriter() override;
};
