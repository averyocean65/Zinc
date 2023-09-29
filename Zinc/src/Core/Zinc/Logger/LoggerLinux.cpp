#include "Logger.h"

#ifndef PLATFORM_WIN

void Logger::change_color(LogSeverity severity) {
    const char* color = "\033[0;37m";   // Light Gray

    // https://www.codeproject.com/Articles/5329247/How-to-Change-Text-Color-in-a-Linux-Terminal
    switch (severity) {
    case LogSeverity::INFO:
        color = "\033[0;97m";           // White
        break;
    case LogSeverity::OK:
        color = "\033[0;92m";           // Green
        break;
    case LogSeverity::WARN:
        color = "\033[0;93m";           // Yellow
        break;
    case LogSeverity::ERR:
        color = "\033[0;91m";           // Red
        break;
    case LogSeverity::FATAL:
        color = "\033[0;31m";           // Dark Red
        break;
    default:
        break;
    }

    std::cout << color;
}

#endif