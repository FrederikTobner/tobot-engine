/**
 * @file logger.h
 * @brief Declarations regarding the logger
 */

#pragma once

#include "../pre_compiled_header.h"

#include "tobot_io.h"

/// @brief The logging namespace
namespace Tobot::Tooling::Logging {
#define LOG_TRACE(...)       (Tobot::Tooling::Logging::Logger::Trace(__VA_ARGS__))
#define LOG_DEBUG(...)       (Tobot::Tooling::Logging::Logger::Debug(__VA_ARGS__))
#define LOG_INFO(...)        (Tobot::Tooling::Logging::Logger::Info(__VA_ARGS__))
#define LOG_WARN(...)        (Tobot::Tooling::Logging::Logger::Warn(__VA_ARGS__))
#define LOG_ERROR(...)       (Tobot::Tooling::Logging::Logger::Error(__VA_ARGS__))
#define LOG_CRITICAL(...)    (Tobot::Tooling::Logging::Logger::Critical(__VA_ARGS__))

#define LOG_TRACE_AT(...)    (Tobot::Tooling::Logging::Logger::Trace(__LINE__, __FILE__, __VA_ARGS__))
#define LOG_DEBUG_AT(...)    (Tobot::Tooling::Logging::Logger::Debug(__LINE__, __FILE__, __VA_ARGS__))
#define LOG_INFO_AT(...)     (Tobot::Tooling::Logging::Logger::Info(__LINE__, __FILE__, __VA_ARGS__))
#define LOG_WARN_AT(...)     (Tobot::Tooling::Logging::Logger::Warn(__LINE__, __FILE__, __VA_ARGS__))
#define LOG_ERROR_AT(...)    (Tobot::Tooling::Logging::Logger::Error(__LINE__, __FILE__, __VA_ARGS__))
#define LOG_CRITICAL_AT(...) (Tobot::Tooling::Logging::Logger::Critical(__LINE__, __FILE__, __VA_ARGS__))

    /// @brief The loglevel priorities that are avialable
    enum LogPriority {
        TRACE_PRIORITY,
        DEBUG_PRIORITY,
        INFO_PRIORITY,
        WARN_PRIORITY,
        ERROR_PRIORITY,
        CRITICAL_PRIORITY
    };

    /// @brief The logger class
    class Logger {
        public:
            /// @brief Changes the priority of the logger insance
            /// @param new_priority The new priority that is set
            static void setPriority(LogPriority new_priority) {
                get_Instance().set_priority(new_priority);
            }

            /// @brief Enables writing the logs to afile
            static void enableFileOutput() {
                get_Instance().enable_file_out();
            }

            /// @brief Changes the time-format of the logger insance
            /// @param new_format The new time-format that is set
            static void setTimeStampFormat(char const * new_format) {
                get_Instance().set_time_stamp_format(new_format);
            }

            /// @brief  Changes the log level colors of the logger insance
            /// @param logLevelColors The new log level colors that are set
            static void setLogLevelColors(uint32_t logLevelColors[6]) {
                get_Instance().set_log_level_colors(logLevelColors);
            }

            /// @brief Logs the arguments with the specified format at the trace logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Trace(char const * format, Args... args) {
                get_Instance().log(TRACE_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the trace logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Trace(std::string format, Args... args) {
                Trace(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the debug logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Debug(char const * format, Args... args) {
                get_Instance().log(DEBUG_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the debug logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Debug(std::string format, Args... args) {
                Debug(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the info logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Info(char const * format, Args... args) {
                get_Instance().log(INFO_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the info logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Info(std::string format, Args... args) {
                Info(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the warn logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Warn(char const * format, Args... args) {
                get_Instance().log(WARN_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the warn logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Warn(std::string format, Args... args) {
                Warn(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the error logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Error(char const * format, Args... args) {
                get_Instance().log(ERROR_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the error logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Error(std::string format, Args... args) {
                Error(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the critical logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Critical(char const * format, Args... args) {
                get_Instance().log(CRITICAL_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the critical logging level
            /// @tparam ...Args Template for the argumens
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Critical(std::string format, Args... args) {
                Critical(format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the trace logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Trace(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, TRACE_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the trace logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Trace(int line, char const * source_file, std::string format, Args... args) {
                Trace(line, source_file, format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the debug logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Debug(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, DEBUG_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the debug logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Debug(int line, char const * source_file, std::string format, Args... args) {
                Debug(line, source_file, format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the info logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Info(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, INFO_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the info logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Info(int line, char const * source_file, std::string format, Args... args) {
                Info(line, source_file, format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the warn logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Warn(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, WARN_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the warn logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Warn(int line, char const * source_file, std::string format, Args... args) {
                Warn(line, source_file, format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the error logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Error(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, ERROR_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the error logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Error(int line, char const * source_file, std::string format, Args... args) {
                Error(line, source_file, format.c_str(), args...);
            }

            /// @brief Logs the arguments with the specified format at the critical logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Critical(int line, char const * source_file, char const * format, Args... args) {
                get_Instance().log(line, source_file, CRITICAL_PRIORITY, format, args...);
            }

            /// @brief Logs the arguments with the specified format at the critical logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            static void Critical(int line, char const * source_file, std::string format, Args... args, bool) {
                Critical(line, source_file, format.c_str(), args...);
            }

        private:
            /// @brief The current log priority of the logger
            LogPriority priority = LogPriority::INFO_PRIORITY;
            /// @brief The logLevel colors of the logger - 0x00RRGGBB (green, limette, deepskyblue, orange, orangered,
            /// red)
            uint32_t logLevelColors[6] = {0x00008000, 0x0000ff00, 0x0000bfff, 0x00ffa500, 0x00ff4500, 0x00ff0000};
            /// @brief The path of the file the logger writes to, if logging to a file is enabled
            char const * filepath;
            /// @brief The timestamp format of the logger
            char const * timeStampFormat = "%d.%m.%Y - %H:%M:%S";
            /// @brief Pointer to the output file the logger writes to, if logging to a file is enabled
            FILE * file;
            /// @brief for thread safety
            std::mutex log_mutex;
            /// @brief The names of the loglevels the logger provides
            char const * const logLevelStrings[6] = {"Trace", "Debug", "Info", "Warn", "Error", "Critical"};

            /// @brief Constructor of the logger
            Logger();

            /// @brief
            /// @param
            Logger(Logger const &) = delete;

            /// @brief
            /// @param
            /// @return
            Logger & operator=(Logger const &) = delete;

            /// @brief Destructor of the logger
            ~Logger();

            /// @brief Gets the logger instance
            /// @return The logger instance
            static Logger & get_Instance() {
                static Logger logger;
                return logger;
            }

            /// @brief Enables fiile output for the logger
            /// @warning If the logs folder can not be created the program exits
            auto enable_file_out() -> void;

            /// @brief Enables fiile output for the logger
            /// @warning If the logs folder can not be created the program exits
            /// @param fileName The name of the output file
            auto enable_file_out(char const * fileName) -> void;

            /// @brief Releseases the file that is currently used by the logger
            auto free_file() -> void;

            /// @brief Sets the logging priority of the logger
            /// @param priority The logging priority
            auto set_priority(LogPriority priority) -> void;

            /// @brief Sets the time stamp format of the logger
            /// @param format The time stamp format
            auto set_time_stamp_format(char const * format) -> void;

            /// @brief Sets the logging colors of the logger
            /// @param colors The logging colors
            auto set_log_level_colors(uint32_t colors[6]) -> void;

            /// @brief   Logs the arguments with the specified format at the specified logging level
            /// @tparam ...Args Template for the argumens
            /// @param log_priority The logging priority of the message
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            void log(LogPriority log_priority, char const * format, Args... args) {
                if (this->priority <= log_priority) {
                    const std::lock_guard<std::mutex> lock(log_mutex);
                    time_t current_time = time(0);
                    tm * timestamp = localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, get_Instance().timeStampFormat, timestamp);
                    std::cout << buffer << " - [";

                    // Changing the color of the output to the color of the log priority
                    Tobot::IO::setConsoleColor((logLevelColors[log_priority] >> 16) & 0xFF,
                                               (logLevelColors[log_priority] >> 8) & 0xFF,
                                               logLevelColors[log_priority] & 0xFF);

                    std::cout << logLevelStrings[log_priority];

                    // Resetting the color of the output to white
                    Tobot::IO::resetConsoleColor();

                    if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }
                    // Changing the color of the output to red if the log priority is critical
                    if (log_priority == CRITICAL_PRIORITY) {
                        Tobot::IO::setConsoleColor(0xFF, 0x00, 0x00);
                    }

                    printf(format, args...);
                    std::cout << "\n";

                    // Resetting the color of the output to white if the log priority is critical
                    if (log_priority == CRITICAL_PRIORITY) {
                        Tobot::IO::resetConsoleColor();
                    }

                    if (this->file) {
                        fprintf(this->file, "%s - [%s]\t", buffer, logLevelStrings[log_priority]);
                        if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                            fprintf(this->file, "\t");
                        }
                        fprintf(this->file, format, args...);
                        fprintf(this->file, "\n");
                    }
                }
            }

            /// @brief Logs the arguments with the specified format at the specified logging level adding the file name
            /// and the line where the log call occured
            /// @tparam ...Args Template for the argumens
            /// @param line The line number that is logged
            /// @param source_file The name of the source file
            /// @param log_priority The logging priority of the message
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            void log(int line_number, char const * source_file, LogPriority log_priority, char const * format,
                     Args... args) {
                if (this->priority <= log_priority) {
                    const std::lock_guard<std::mutex> lock(log_mutex);
                    time_t current_time = time(0);
                    tm * timestamp = localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, this->get_Instance().timeStampFormat, timestamp);
                    std::cout << buffer << " - [";
                    Tobot::IO::setConsoleColor((logLevelColors[log_priority] >> 16) & 0xFF,
                                               (logLevelColors[log_priority] >> 8) & 0xFF,
                                               logLevelColors[log_priority] & 0xFF);
                    std::cout << logLevelStrings[log_priority];
                    Tobot::IO::resetConsoleColor();
                    if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }

                    // Changing the color of the output to red if the log priority is critical
                    if (log_priority == CRITICAL_PRIORITY) {
                        Tobot::IO::setConsoleColor(0xFF, 0x00, 0x00);
                    }

                    printf(format, args...);

                    // Resetting the color of the output to white if the log priority is critical
                    if (log_priority == CRITICAL_PRIORITY) {
                        Tobot::IO::resetConsoleColor();
                    }

                    std::cout << " (on line " << line_number << " in " << source_file << ")\n";
                    if (this->file) {
                        fprintf(this->file, "%s - [%s]\t", buffer, logLevelStrings[log_priority]);
                        if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                            fprintf(this->file, "\t");
                        }
                        fprintf(this->file, format, args...);
                        fprintf(this->file, " (on line %d in %s)", line_number, source_file);
                        fprintf(this->file, "\n");
                    }
                }
            }
    };
} // namespace Tobot::Tooling::Logging
