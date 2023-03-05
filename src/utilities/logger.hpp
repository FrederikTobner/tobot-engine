#pragma once

#include <mutex>
#include <sstream>
#include <string>

#include <stdio.h>
#include <iostream>

#ifdef OS_WINDOWS
#include <windows.h>
#endif

namespace Tobot::Utilities
{
#define LOG_TRACE(message, ...) (Tobot::Utilities::Logger::Trace(message, __VA_ARGS__))
#define LOG_DEBUG(message, ...) (Tobot::Utilities::Logger::Debug(message, __VA_ARGS__))
#define LOG_INFO(message, ...) (Tobot::Utilities::Logger::Info(message, __VA_ARGS__))
#define LOG_WARN(message, ...) (Tobot::Utilities::Logger::Warn(message, __VA_ARGS__))
#define LOG_ERROR(message, ...) (Tobot::Utilities::Logger::Error(message, __VA_ARGS__))
#define LOG_CRITICAL(message, ...) (Tobot::Utilities::Logger::Critical(message, __VA_ARGS__))

#define LOG_TRACE_AT(message, ...) (Tobot::Utilities::Logger::Trace(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_DEBUG_AT(message, ...) (Tobot::Utilities::Logger::Debug(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_INFO_AT(message, ...) (Tobot::Utilities::Logger::Info(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_WARN_AT(message, ...) (Tobot::Utilities::Logger::Warn(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_ERROR_AT(message, ...) (Tobot::Utilities::Logger::Error(__LINE__, __FILE__, message, __VA_ARGS__))
#define LOG_CRITICAL_AT(message, ...) (Tobot::Utilities::Logger::Critical(__LINE__, __FILE__, message, __VA_ARGS__))

    enum LogPriority
    {
        TRACE_PRIORITY,
        DEBUG_PRIORITY,
        INFO_PRIORITY,
        WARN_PRIORITY,
        ERROR_PRIORITY,
        CRITICAL_PRIORITY,
    };

    class Logger
    {
    public:
        static void setPriority(LogPriority new_priority)
        {
            get_Instance().priority = new_priority;
        }

        static void EnableFileOutput()
        {
            get_Instance().enable_file_out();
        }

        static void SetTimeStampFormat(const char *new_format)
        {
            get_Instance().timeStampFormat = new_format;
        }

        static void SetLogLevelColors(uint8_t logLevelColors[6])
        {
            for (size_t i; i < 6; i++)
            {
                get_Instance().logLevelColors[i] = logLevelColors[i];
            }
        }

        template <typename... Args>
        static void Trace(char const *message, Args... args)
        {
            get_Instance().log("Trace", TRACE_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Trace(std::string message, Args... args)
        {
            Trace(message.c_str(), args...);
        }

        template <typename... Args>
        static void Debug(char const *message, Args... args)
        {
            get_Instance().log("Debug", DEBUG_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Debug(std::string message, Args... args)
        {
            Debug(message.c_str(), args...);
        }

        template <typename... Args>
        static void Info(char const *message, Args... args)
        {
            get_Instance().log("Info", INFO_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Info(std::string message, Args... args)
        {
            Info(message.c_str(), args...);
        }

        template <typename... Args>
        static void Warn(char const *message, Args... args)
        {
            get_Instance().log("Warn", WARN_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Warn(std::string message, Args... args)
        {
            Warn(message.c_str(), args...);
        }

        template <typename... Args>
        static void Error(char const *message, Args... args)
        {
            get_Instance().log("Error", ERROR_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Error(std::string message, Args... args)
        {
            Error(message.c_str(), args...);
        }

        template <typename... Args>
        static void Critical(char const *message, Args... args)
        {
            get_Instance().log("Critical", CRITICAL_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Critical(std::string message, Args... args)
        {
            Critical(message.c_str(), args...);
        }

        template <typename... Args>
        static void Trace(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Trace", TRACE_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Trace(bool fromClientApplication, int line, char const *source_file, std::string message, Args... args)
        {
            Trace(line, source_file, message.c_str(), args...);
        }

        template <typename... Args>
        static void Debug(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Debug", DEBUG_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Debug(int line, char const *source_file, std::string message, Args... args)
        {
            Debug(line, source_file, message.c_str(), args...);
        }

        template <typename... Args>
        static void Info(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Info", INFO_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Info(int line, char const *source_file, std::string message, Args... args)
        {
            Info(line, source_file, message.c_str(), args...);
        }

        template <typename... Args>
        static void Warn(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Warn", WARN_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Warn(int line, char const *source_file, std::string message, Args... args)
        {
            Warn(line, source_file, message.c_str(), args...);
        }

        template <typename... Args>
        static void Error(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Error", ERROR_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Error(int line, char const *source_file, std::string message, Args... args)
        {
            Error(line, source_file, message.c_str(), args...);
        }

        template <typename... Args>
        static void Critical(int line, char const *source_file, char const *message, Args... args)
        {
            get_Instance().log(line, source_file, "Critical", CRITICAL_PRIORITY, message, args...);
        }

        template <typename... Args>
        static void Critical(int line, char const *source_file, std::string message, Args... args)
        {
            Critical(line, source_file, message.c_str(), args...);
        }

    private:
        LogPriority priority;
        bool file_output;
        uint8_t logLevelColors[6] = {7, 2, 3, 6, 4, 4};
        char const *filepath;
        char const *timeStampFormat = "%d.%m.%Y - %H:%M:%S";
        FILE *file;
        std::mutex log_mutex; // for thread safety

        Logger();

        Logger(const Logger &) = delete;

        Logger &operator=(const Logger &) = delete;

        ~Logger();

        static Logger &get_Instance()
        {
            static Logger logger;
            return logger;
        }

        template <typename... Args>
        void log(char const *message_priority_str, LogPriority message_priority, char const *message, Args... args)
        {
            if (priority <= message_priority)
            {
                std::scoped_lock lock(log_mutex);
#ifdef OS_WINDOWS
                HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
                std::time_t current_time = std::time(0);
                std::tm *timestamp = std::localtime(&current_time);
                char buffer[80];
                strftime(buffer, 80, get_Instance().timeStampFormat, timestamp);
                printf("%s - [", buffer);
                printf("] - [");
#ifdef OS_WINDOWS
                SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[message_priority]);
#endif
                printf(message_priority_str);
#ifdef OS_WINDOWS
                SetConsoleTextAttribute(console_color, 7);
#endif
                if (strlen(message_priority_str) <= 6)
                    printf("]\t");
                else
                    printf("]\t\t");
#ifdef OS_WINDOWS
                if (message_priority == CRITICAL_PRIORITY)
                {
                    SetConsoleTextAttribute(console_color, 4);
                }
#endif
                printf(message, args...);
                printf("\n");
#ifdef OS_WINDOWS
                if (message_priority == CRITICAL_PRIORITY)
                {
                    SetConsoleTextAttribute(console_color, 7);
                }
#endif
                if (file)
                {
                    fprintf(file, "%s - [%s]\t\t", buffer, message_priority_str);
                    if (strlen(message_priority_str) <= 6)
                        fprintf(file, "\t");
                    fprintf(file, message, args...);
                    fprintf(file, "\n");
                }
            }
        }

        template <typename... Args>
        void log(int line_number, char const *source_file, char const *message_priority_str, LogPriority message_priority, char const *message, Args... args)
        {
            if (priority <= message_priority)
            {
                std::scoped_lock lock(log_mutex);
#ifdef OS_WINDOWS
                HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
                std::time_t current_time = std::time(0);
                std::tm *timestamp = std::localtime(&current_time);
                char buffer[80];
                strftime(buffer, 80, get_Instance().timeStampFormat, timestamp);
                printf("%s - [", buffer);
                printf("] - [");
#ifdef OS_WINDOWS
                SetConsoleTextAttribute(console_color, get_Instance().logLevelColors[message_priority]);
#endif
                printf(message_priority_str);
#ifdef OS_WINDOWS
                SetConsoleTextAttribute(console_color, 7);
#endif
                if (strlen(message_priority_str) <= 6)
                    printf("]\t");
                else
                    printf("]\t\t");
#ifdef OS_WINDOWS
                if (message_priority == CRITICAL_PRIORITY)
                {
                    SetConsoleTextAttribute(console_color, 4);
                }
#endif
                printf(message, args...);
#ifdef OS_WINDOWS
                if (message_priority == CRITICAL_PRIORITY)
                {
                    SetConsoleTextAttribute(console_color, 7);
                }
#endif
                printf(" (on line %d in %s)", line_number, source_file);
                printf("\n");
                if (file)
                {
                    fprintf(file, "%s - [%s]\t\t", buffer, message_priority_str);
                    fprintf(file, message, args...);
                    fprintf(file, " (on line %d in %s)", line_number, source_file);
                    fprintf(file, "\n");
                }
            }
        }

        void enable_file_out();

        void enable_file_out(char const *fileName);

        void free_file();

        void ensure_logs_directory_exists();
    };
}
