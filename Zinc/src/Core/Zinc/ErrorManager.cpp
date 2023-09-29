#include "ErrorManager.h"

std::shared_ptr<ErrorManager> ErrorManager::s_EngineManager = std::make_unique<ErrorManager>();

void ErrorManager::Create(const char* fmt, ...) {	
	va_list args;
	va_start(args, fmt);

	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), fmt, args);

	va_end(args);
	m_LatestError = buffer;
}

const char* ErrorManager::GetLatest() {
	return m_LatestError;
}

std::shared_ptr<ErrorManager> ErrorManager::GetEngineManager() {
	return s_EngineManager;
}