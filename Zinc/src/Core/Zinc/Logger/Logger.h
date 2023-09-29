#pragma once
#include <iostream>
#include <memory>
#include "../Core.h"

#define ENGINE_LOGGER Logger::GetEngineLogger()
#define APP_LOGGER Logger::GetApplicationLogger()

enum class LogSeverity {
	DEBUG,
	INFO,
	OK,
	WARN,
	ERR,
	FATAL
};

class ZINC_API Logger sealed
{
public:
	Logger(const char* name);

	void log(LogSeverity severity, const char* fmt, ...);
		
	void debug(const char* fmt, ...);
	void ok(const char* fmt, ...);
	void info(const char* fmt, ...);
	void warn(const char* fmt, ...);
	void error(const char* fmt, ...);
	void fatal(const char* fmt, ...);

	void assert(bool condition, const char* callingFunction);

	inline static std::shared_ptr<Logger> GetEngineLogger();
	inline static std::shared_ptr<Logger> GetApplicationLogger();

private:
	void change_color(LogSeverity severity);
	inline void log_internal(LogSeverity severity, const char* msg);

	const char* get_severity_name(LogSeverity severity);

	static std::shared_ptr<Logger> s_EngineLogger;
	static std::shared_ptr<Logger> s_ApplicationLogger;

	const char* m_Name;
	int m_LogCount;
};