#include "Logger.h"
#include <cstdarg>
#include <iostream>

#pragma region Constants
const int BUFFER_SIZE = 1024;

const char* Logger::get_severity_name(LogSeverity severity) {
    switch (severity) {
    case LogSeverity::DEBUG:
        return "DEBUG";
    case LogSeverity::INFO:
        return "INFO";
    case LogSeverity::OK:
        return "OK";
    case LogSeverity::WARN:
        return "WARN";
    case LogSeverity::ERR:
        return "ERROR";
    case LogSeverity::FATAL:
        return "FATAL";
    default:
        return "UNKNOWN";
    }
}
#pragma endregion

#pragma region Constructors
Logger::Logger(const char* name)
    : m_Name(name), m_LogCount(0) { }
#pragma endregion

#pragma region Static Members
std::shared_ptr<Logger> Logger::s_EngineLogger = std::make_shared<Logger>("ZINC");
std::shared_ptr<Logger> Logger::s_ApplicationLogger = std::make_shared<Logger>("Application");
#pragma endregion

#pragma region Public Member Functions
void Logger::log(LogSeverity severity, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(severity, buffer);
}

#pragma region Preset Log Severity Functions
void Logger::debug(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::DEBUG, buffer);
}

void Logger::info(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::INFO, buffer);
}

void Logger::ok(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::OK, buffer);
}

void Logger::warn(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::WARN, buffer);
}

void Logger::error(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::ERR, buffer);
}

void Logger::fatal(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[BUFFER_SIZE];
    vsnprintf(buffer, BUFFER_SIZE, fmt, args);
    va_end(args);

    log_internal(LogSeverity::FATAL, buffer);
}
#pragma endregion

void Logger::assert(bool condition, const char* callingFunction) {
    if (!condition) {
        error("Failed assert from %s!", callingFunction);
    }
}
#pragma endregion

#pragma region Private Member Functions

/// <summary>
/// The core log function used in the ZINC Logger.
/// Responsible for printing to the output buffer
/// </summary>
/// <param name="severity">The Log Severity</param>
/// <param name="msg">Message in form of a constant string</param>
void Logger::log_internal(LogSeverity severity, const char* msg) {
    // First part of log (Name + Beginning of severity wrapper)
    std::cout << "<" << m_Name << "> :: [ ";

    // Second part of log (Severity Content)
    change_color(severity);
    std::cout << get_severity_name(severity);

    // Third part of log (Close severity wrapper + message)
    change_color(LogSeverity::DEBUG);
    std::cout << " ] - " << msg << std::endl;

    // Increment log count
    m_LogCount++;
}
#pragma endregion

#pragma region Static Member Functions
std::shared_ptr<Logger> Logger::GetEngineLogger() { return s_EngineLogger; }
std::shared_ptr<Logger> Logger::GetApplicationLogger() { return s_ApplicationLogger; }
#pragma endregion