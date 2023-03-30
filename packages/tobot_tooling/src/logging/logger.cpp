/**
 * @file logger.cpp
 * @brief Definitions regarding the logger
 */

#include "logger.h"

#include "tobot_io.h"

using namespace Tobot::Tooling::Logging;

Logger::Logger() {
}

Logger::~Logger() {
    free_file();
}

void Logger::enable_file_out() {
    if (Tobot::IO::Directory::ensure_directory_exists(LOGS_FOLDER_PATH)) {
        exit(70);
    }
    std::time_t current_time = std::time(0);
    std::tm * timestamp = std::localtime(&current_time);
    char buffer[120];
    *buffer = '\0';
    char fileNameBuffer[80];
    strftime(fileNameBuffer, 80, "%d_%m_%Y_%H-%M-%S", timestamp);
    strcat(buffer, LOGS_FOLDER_PATH);
    strcat(buffer, fileNameBuffer);
    filepath = strcat(buffer, "_log.txt");
    if (file) {
        fclose(file);
    }
    file = fopen(filepath, "w");
    if (!file) {
        std::cerr << "failed to open file at " << filepath;
    }
}

void Logger::free_file() {
    if (file) {
        fclose(file);
        file = NULL;
    }
}
