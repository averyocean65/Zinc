#pragma once
#include "Logger/Logger.h"
#include "ErrorManager.h"
#include "Graphics/Zinc.h"

extern int appMain(int argc, char** argv);

int init() {
	return graphics_init();
}

int main(int argc, char **argv) {
	// Make sure ZINC initialized
	if (init() != ZINC_SUCCESS) {
		ENGINE_LOGGER->error("Failed to initialize ZINC!");
		ENGINE_LOGGER->error("Error: %s", ENGINE_MANAGER->GetLatest());
		return ZINC_FAILURE;
	}

	// Load the host application
	ENGINE_LOGGER->ok("Initialized ZINC!");
	ENGINE_LOGGER->info("Loading app_main()...");
	return appMain(argc, argv);
}