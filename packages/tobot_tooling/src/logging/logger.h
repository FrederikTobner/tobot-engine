/**
 * @file logger.h
 * @brief Declarations regarding the logger
 */

#pragma once

/// @brief The logging namespace
namespace Tobot::Tooling::Logging {
#define LOG_TRACE(format, ...)    (Tobot::Tooling::Logging::Logger::Trace(format, __VA_ARGS__))
#define LOG_DEBUG(format, ...)    (Tobot::Tooling::Logging::Logger::Debug(format, __VA_ARGS__))
#define LOG_INFO(format, ...)     (Tobot::Tooling::Logging::Logger::Info(format, __VA_ARGS__))
#define LOG_WARN(format, ...)     (Tobot::Tooling::Logging::Logger::Warn(format, __VA_ARGS__))
#define LOG_ERROR(format, ...)    (Tobot::Tooling::Logging::Logger::Error(format, __VA_ARGS__))
#define LOG_CRITICAL(format, ...) (Tobot::Tooling::Logging::Logger::Critical(format, __VA_ARGS__))

#define LOG_TRACE_AT(format, ...) (Tobot::Tooling::Logging::Logger::Trace(__LINE__, __FILE__, format, __VA_ARGS__))
#define LOG_DEBUG_AT(format, ...) (Tobot::Tooling::Logging::Logger::Debug(__LINE__, __FILE__, format, __VA_ARGS__))
#define LOG_INFO_AT(format, ...)  (Tobot::Tooling::Logging::Logger::Info(__LINE__, __FILE__, format, __VA_ARGS__))
#define LOG_WARN_AT(format, ...)  (Tobot::Tooling::Logging::Logger::Warn(__LINE__, __FILE__, format, __VA_ARGS__))
#define LOG_ERROR_AT(format, ...) (Tobot::Tooling::Logging::Logger::Error(__LINE__, __FILE__, format, __VA_ARGS__))
#define LOG_CRITICAL_AT(format, ...) \
    (Tobot::Tooling::Logging::Logger::Critical(__LINE__, __FILE__, format, __VA_ARGS__))

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
                get_Instance().priority = new_priority;
            }

            /// @brief Enables writing the logs to afile
            static void EnableFileOutput() {
                get_Instance().enable_file_out();
            }

            /// @brief Changes the time-format of the logger insance
            /// @param new_format The new time-format that is set
            static void SetTimeStampFormat(char const * new_format) {
                get_Instance().timeStampFormat = new_format;
            }

            /// @brief  Changes the log level colors of the logger insance
            /// @param logLevelColors The new log level colors that are set
            static void SetLogLevelColors(uint8_t logLevelColors[6]) {
                for (size_t i; i < 6; i++) {
                    get_Instance().logLevelColors[i] = logLevelColors[i];
                }
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
            std::atomic<LogPriority> priority = LogPriority::INFO_PRIORITY;
            /// @brief The logLevel colors of the logger
            std::atomic<uint8_t> logLevelColors[6] = {7, 2, 3, 6, 4, 4};
            /// @brief The path of the file the logger writes to, if logging to a file is enabled
            std::atomic<char const *> filepath;
            /// @brief The timestamp format of the logger
            std::atomic<char const *> timeStampFormat = "%d.%m.%Y - %H:%M:%S";
            /// @brief Pointer to the output file the logger writes to, if logging to a file is enabled
            std::atomic<FILE *> file;
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

            /// @brief   Logs the arguments with the specified format at the specified logging level
            /// @tparam ...Args Template for the argumens
            /// @param log_priority The logging priority of the message
            /// @param format The format that is used to format the arguments
            /// @param ...args The arguments that are formated
            template <typename... Args>
            void log(LogPriority log_priority, char const * format, Args... args) {
                if (this->priority <= log_priority) {
                    std::scoped_lock lock(log_mutex);
                    std::time_t current_time = std::time(0);
                    std::tm * timestamp = std::localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, get_Instance().timeStampFormat, timestamp);
                    std::cout << buffer << " - [";
#ifdef OS_WINDOWS
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[log_priority]);
#endif
                    std::cout << logLevelStrings[log_priority];
#ifdef OS_WINDOWS
                    SetConsoleTextAttribute(console_color, 7);
#endif
                    if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }
#ifdef OS_WINDOWS
                    if (log_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 4);
                    }
#endif
                    printf(format, args...);
                    std::cout << std::endl;
#ifdef OS_WINDOWS
                    if (log_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 7);
                    }
#endif
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
                    std::scoped_lock lock(log_mutex);
                    std::time_t current_time = std::time(0);
                    std::tm * timestamp = std::localtime(&current_time);
                    char buffer[80];
                    strftime(buffer, 80, this->get_Instance().timeStampFormat, timestamp);
                    std::cout << buffer << " - [";
#ifdef OS_WINDOWS
                    HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[log_priority]);
#endif
                    std::cout << logLevelStrings[log_priority];
#ifdef OS_WINDOWS
                    SetConsoleTextAttribute(console_color, 7);
#endif
                    if (log_priority == LogPriority::CRITICAL_PRIORITY) {
                        std::cout << "]\t";
                    } else {
                        std::cout << "]\t\t";
                    }
#ifdef OS_WINDOWS
                    if (log_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 4);
                    }
#endif
                    printf(format, args...);
#ifdef OS_WINDOWS
                    if (log_priority == CRITICAL_PRIORITY) {
                        SetConsoleTextAttribute(console_color, 7);
                    }
#endif
                    std::cout << " (on line " << line_number << " in " << source_file << std::endl;
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

            /// @brief Enables fiile output for the logger
            /// @warning If the logs folder can not be created the program exits
            void enable_file_out();

            /// @brief Enables fiile output for the logger
            /// @warning If the logs folder can not be created the program exits
            /// @param fileName The name of the output file
            void enable_file_out(char const * fileName);

            /// @brief Releseases the file that is currently used by the logger
            void free_file();
    };
} // namespace Tobot::Tooling::Logging
