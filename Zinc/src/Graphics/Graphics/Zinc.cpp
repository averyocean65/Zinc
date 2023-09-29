#include "Zinc.h"
#include "ZincCore.h"

int graphics_init() {
	if (!glfwInit())
	{
		ENGINE_MANAGER->Create("Failed to initialize GLFW");
		return ZINC_FAILURE;
	}

	ENGINE_LOGGER->ok("Initialized GLFW");
	return ZINC_SUCCESS;
}