#pragma once
#include <iostream>
#include <cstdarg>
#include <memory>
#include "Core.h"

#define ENGINE_MANAGER ErrorManager::GetEngineManager()

class ZINC_API ErrorManager sealed
{
public:
	void Create(const char* fmt, ...);
	const char* GetLatest();

	inline static std::shared_ptr<ErrorManager> GetEngineManager();
private:
	char* m_LatestError;

	static std::shared_ptr<ErrorManager> s_EngineManager;
};