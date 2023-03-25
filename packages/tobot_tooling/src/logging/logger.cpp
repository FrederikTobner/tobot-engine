/**
 * @file logger.cpp
 * @brief Definitions regarding the logger
 */

#include "logger.h"

#include <ctime>

using namespace Tobot::Tooling::Logging;

Logger::Logger() {
}

Logger::~Logger() {
    free_file();
}

void Logger::enable_file_out() {
    ensure_logs_directory_exists();
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

void Logger::ensure_logs_directory_exists() {
#ifdef OS_WINDOWS
    DWORD dataWordAttribute = GetFileAttributes(LOGS_FOLDER_PATH);
    if (dataWordAttribute == INVALID_FILE_ATTRIBUTES) {
        CreateDirectory(LOGS_FOLDER_PATH, NULL);
        dataWordAttribute = GetFileAttributes(LOGS_FOLDER_PATH);
        if (dataWordAttribute == INVALID_FILE_ATTRIBUTES) {
            std::cerr << "Can not create logs directory!\n";
            exit(70);
        }
    } else if (!(dataWordAttribute & FILE_ATTRIBUTE_DIRECTORY)) {
        std::cerr << "Logs is not a directory\n";
        exit(70);
    }
#endif
#ifdef OS_LINUX
    DIR * resultsDirectory = opendir(LOGS_FOLDER_PATH);
    if (resultsDirectory) {
        closedir(resultsDirectory);
    } else if (ENOENT == errno) {
        // If the directory does not exists we need to create it
        mkdir(LOGS_FOLDER_PATH, 0700);
        resultsDirectory = opendir(LOGS_FOLDER_PATH);
        if (resultsDirectory) {
            closedir(resultsDirectory);
        } else {
            std::cerr << "Can not create logs directory!\n";
            exit(70);
        }
    } else {
        std::cerr << "Can not access logs directory!\n";
        exit(70);
    }
#endif
}

void Logger::free_file() {
    if (file) {
        fclose(file);
        file = NULL;
    }
}
