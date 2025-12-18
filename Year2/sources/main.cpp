#include <iostream>
#include "../Logging/ConsoleLogger.h"
#include "../Logging/FileLogger.h"
#include "../Logging/FileWriter.h"

int main() {
    try {
        // Console logger
        ConsoleLogger console;
        console.log(LogLevel::INFO, "Console logger initialised");

        // File writer + file logger
        FileWriter writer("test_log.txt");
        FileLogger fileLogger(&writer);

        console.log(LogLevel::ACTION, "Performing an action");
        fileLogger.log(LogLevel::ACTION, "Performed an action and persisted it");
        console.log(LogLevel::WARNING, "This is a warning");
        fileLogger.log(LogLevel::ERROR, "An error occurred (logged to file)");

        std::cout << "Finished logging test. Check test_log.txt." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
