#pragma once

#include <mutex>
#include <sstream>
#include <string>

#include <iostream>
#include <stdio.h>

#ifdef OS_WINDOWS
#include <windows.h>
#endif

namespace Tobot::Tooling::Logging {
#define LOG_TRACE(message, ...)       (Tobot::Tooling::Logging::Logger::Trace(message, __VA_ARGS__))
#define LOG_DEBUG(message, ...)       (Tobot::Tooling::Logging::Logger::Debug(message, __VA_ARGS__))
#define LOG_INFO(message, ...)        (Tobot::Tooling::Logging::Logger::Info(message, __VA_ARGS__))
#define LOG_WARN(message, ...)        (Tobot::Tooling::Logging::Logger::Warn(message, __VA_ARGS__))
#define LOG_ERROR(message, ...)       (Tobot::Tooling::Logging::Logger::Error(message, __VA_ARGS__))
#define LOG_CRITICAL(message, ...)    (Tobot::Tooling::Logging::Logger::Critical(message, __VA_ARGS__))

#define LOG_TRACE_AT(message, ...)    (Tobot::Tooling::Logging::Logger::Trace(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_DEBUG_AT(message, ...)    (Tobot::Tooling::Logging::Logger::Debug(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_INFO_AT(message, ...)     (Tobot::Tooling::Logging::Logger::Info(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_WARN_AT(message, ...)     (Tobot::Tooling::Logging::Logger::Warn(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_ERROR_AT(message, ...)    (Tobot::Tooling::Logging::Logger::Error(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_CRITICAL_AT(message, ...) (Tobot::Tooling::Logging::Logger::Critical(__LINE__, __FILE__, message, __VA_ARGS__))

    enum LogPriority {
        TRACE_PRIORITY,
        DEBUG_PRIORITY,
        INFO_PRIORITY,
        WARN_PRIORITY,
        ERROR_PRIORITY,
        CRITICAL_PRIORITY
    };

    class Logger {
        public:
            static void setPriority(LogPriority new_priority) {
                get_Instance().priority = new_priority;
            }

            static void EnableFileOutput() {
                get_Instance().enable_file_out();
            }

            static void SetTimeStampFormat(const char * new_format) {
                get_Instance().timeStampFormat = new_format;
            }

            static void SetLogLevelColors(uint8_t logLevelColors[6]) {
                for (size_t i; i < 6; i++) {
                    get_Instance().logLevelColors[i] = logLevelColors[i];
                }
            }

            template <typename... Args>
            static void Trace(char const * message, Args... args) {
                get_Instance().log(TRACE_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Trace(std::string message, Args... args) {
                Trace(message.c_str(), args...);
            }

            template <typename... Args>
            static void Debug(char const * message, Args... args) {
                get_Instance().log(DEBUG_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Debug(std::string message, Args... args) {
                Debug(message.c_str(), args...);
            }

            template <typename... Args>
            static void Info(char const * message, Args... args) {
                get_Instance().log(INFO_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Info(std::string message, Args... args) {
                Info(message.c_str(), args...);
            }

            template <typename... Args>
            static void Warn(char const * message, Args... args) {
                get_Instance().log(WARN_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Warn(std::string message, Args... args) {
                Warn(message.c_str(), args...);
            }

            template <typename... Args>
            static void Error(char const * message, Args... args) {
                get_Instance().log(ERROR_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Error(std::string message, Args... args) {
                Error(message.c_str(), args...);
            }

            template <typename... Args>
            static void Critical(char const * message, Args... args) {
                get_Instance().log(CRITICAL_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Critical(std::string message, Args... args) {
                Critical(message.c_str(), args...);
            }

            template <typename... Args>
            static void Trace(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, TRACE_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Trace(bool fromClientApplication, int line, char const * source_file, std::string message,
                              Args... args) {
                Trace(line, source_file, message.c_str(), args...);
            }

            template <typename... Args>
            static void Debug(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, DEBUG_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Debug(int line, char const * source_file, std::string message, Args... args) {
                Debug(line, source_file, message.c_str(), args...);
            }

            template <typename... Args>
            static void Info(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, INFO_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Info(int line, char const * source_file, std::string message, Args... args) {
                Info(line, source_file, message.c_str(), args...);
            }

            template <typename... Args>
            static void Warn(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, WARN_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Warn(int line, char const * source_file, std::string message, Args... args) {
                Warn(line, source_file, message.c_str(), args...);
            }

            template <typename... Args>
            static void Error(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, ERROR_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Error(int line, char const * source_file, std::string message, Args... args) {
                Error(line, source_file, message.c_str(), args...);
            }

            template <typename... Args>
            static void Critical(int line, char const * source_file, char const * message, Args... args) {
                get_Instance().log(line, source_file, CRITICAL_PRIORITY, message, args...);
            }

            template <typename... Args>
            static void Critical(int line, char const * source_file, std::string message, Args... args, bool) {
                Critical(line, source_file, message.c_str(), args...);
            }

        private:
            LogPriority priority = LogPriority::INFO_PRIORITY;
            uint8_t logLevelColors[6] = {7, 2, 3, 6, 4, 4};
            char const * filepath;
            char const * timeStampFormat = "%d.%m.%Y - %H:%M:%S";
            FILE * file;
            std::mutex log_mutex; // for thread safety
            char const * logLevelStrings[6] = {"Trace", "Debug", "Info", "Warn", "Error", "Critical"};

            Logger();

            Logger(const Logger &) = delete;

            Logger & operator=(const Logger &) = delete;

            ~Logger();

            static Logger & get_Instance() {
                static Logger logger;
                return logger;
            }

            template <typename... Args>
            void log(LogPriority message_priority, char const * message, Args... args) {
                if (this->priority <= message_priority) {
                    std::scoped_lock lock(log_mutex);
                    std::time_t current_time = std::time(0);
                    std::tm * timestamp = std::localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, get_Instance().timeStampFormat, timestamp);
                    printf("%s - [", buffer);
#ifdef OS_WINDOWS
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[message_priority]);
#endif
                    std::cout << logLevelStrings[message_priority];
#ifdef OS_WINDOWS
                    SetConsoleTextAttribute(console_color, 7);
#endif
                    if (message_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }
#ifdef OS_WINDOWS
                    if (message_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 4);
                    }
#endif
                    printf(message, args...);
                    std::cout << "\n";
#ifdef OS_WINDOWS
                    if (message_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 7);
                    }
#endif
                    if (this->file) {
                        fprintf(this->file, "%s - [%s]\t", buffer, logLevelStrings[message_priority]);
                        if (message_priority == LogPriority::CRITICAL_PRIORITY) {
                            fprintf(this->file, "\t");
                        }
                        fprintf(this->file, message, args...);
                        fprintf(this->file, "\n");
                    }
                }
            }

            template <typename... Args>
            void log(int line_number, char const * source_file, LogPriority message_priority, char const * message,
                     Args... args) {
                if (this->priority <= message_priority) {
                    std::scoped_lock lock(log_mutex);
                    std::time_t current_time = std::time(0);
                    std::tm * timestamp = std::localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, this->get_Instance().timeStampFormat, timestamp);
                    printf("%s - [", buffer);
#ifdef OS_WINDOWS
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[message_priority]);
#endif
                    std::cout << logLevelStrings[message_priority];
#ifdef OS_WINDOWS
                    SetConsoleTextAttribute(console_color, 7);
#endif
                    if (message_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }
#ifdef OS_WINDOWS
                    if (message_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 4);
                    }
#endif
                    printf(message, args...);
#ifdef OS_WINDOWS
                    if (message_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 7);
                    }
#endif
                    printf(" (on line %d in %s)", line_number, source_file);
                    std::cout << "\n";
                    if (this->file) {
                        fprintf(this->file, "%s - [%s]\t", buffer, logLevelStrings[message_priority]);
                        if (message_priority == LogPriority::CRITICAL_PRIORITY) {
                            fprintf(this->file, "\t");
                        }
                        fprintf(this->file, message, args...);
                        fprintf(this->file, " (on line %d in %s)", line_number, source_file);
                        fprintf(this->file, "\n");
                    }
                }
            }

            void enable_file_out();

            void enable_file_out(char const * fileName);

            void free_file();

            void ensure_logs_directory_exists();
    };
} // namespace Tobot::Utilities
