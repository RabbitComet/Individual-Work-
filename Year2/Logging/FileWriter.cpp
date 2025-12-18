#include "FileWriter.h"
#include <stdexcept>

FileWriter::FileWriter(const std::string& fileName) {
    file.open(fileName, std::ios::out | std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }
}

void FileWriter::write(const std::string& text) {
    if (!file.is_open()) {
        throw std::runtime_error("File not open");
    }
    file << text<< std::endl;
}

FileWriter::~FileWriter() {
    if (file.is_open()) file.close();
}
