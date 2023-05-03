/**
 * @file logger.cpp
 * @brief Definitions regarding the logger
 */

#include "logger.h"

using namespace Tobot::Tooling::Logging;

Logger::Logger() {
}

Logger::~Logger() {
    free_file();
}

auto Logger::enable_file_out() -> void {
    const std::lock_guard<std::mutex> lock(log_mutex);
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
    enable_file_out(filepath);
}

auto Logger::enable_file_out(char const * filePath) -> void {
    if (file) {
        fclose(file);
    }
    file = fopen(filepath, "w");
    if (!file) {
        std::cerr << "failed to open file at " << filepath;
    }
}

auto Logger::free_file() -> void {
    const std::lock_guard<std::mutex> lock(log_mutex);
    if (file) {
        fclose(file);
        file = NULL;
    }
}

auto Logger::set_priority(LogPriority priority) -> void {
    const std::lock_guard<std::mutex> lock(log_mutex);
    priority = priority;
}

auto Logger::set_time_stamp_format(char const * format) -> void {
    const std::lock_guard<std::mutex> lock(log_mutex);
    timeStampFormat = format;
}

auto Logger::set_log_level_colors(uint32_t colors[6]) -> void {
    const std::lock_guard<std::mutex> lock(log_mutex);
    for (int i = 0; i < 6; i++) {
        logLevelColors[i] = colors[i];
    }
}