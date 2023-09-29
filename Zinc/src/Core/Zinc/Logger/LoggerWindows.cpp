#include "Logger.h"

#ifdef PLATFORM_WIN

void Logger::change_color(LogSeverity severity) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
        return;

    int color = 0x0;
    switch (severity) {
    case LogSeverity::INFO:
        color = 0xF;            // White
        break;
    case LogSeverity::OK:
        color = 0xA;            // Green
        break;
    case LogSeverity::WARN:
        color = 0xE;            // Yellow
        break;
    case LogSeverity::ERR:
        color = 0xC;            // Red
        break;
    case LogSeverity::FATAL:
        color = 0x4;            // Dark Red
        break;
    default:
        color = 0x7;            // Grey
        break;
    }

    SetConsoleTextAttribute(hConsole, color);
}

#endif