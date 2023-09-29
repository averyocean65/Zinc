#pragma once

#pragma region Utility Macros
#define BIT(x) 1 << x
#define GET_NAME(t) #t
#pragma endregion

#pragma region Return Types

#define ZINC_SUCCESS			0
#define ZINC_FAILURE			BIT(1)
#define ZINC_NULL				BIT(2)
#define ZINC_ARGS_ERR			BIT(3)

#pragma endregion

#pragma region Exports

// Set up ZINC_API
#ifdef ZINC_BUILD
	#define ZINC_API __declspec(dllexport)
#else
	#define ZINC_API __declspec(dllimport)
#endif

// Platform
#ifdef _WIN32
#define PLATFORM_WIN
#include <Windows.h>
#else
	#define PLATFORM_UNIX
#endif

#pragma endregion