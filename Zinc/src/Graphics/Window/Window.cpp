#include "Window.h"

Window::Window(const char* title, int width, int height)
	: m_Window(glfwCreateWindow(width, height, title, NULL, NULL))
{
	if (m_Window == nullptr) {
		glfwTerminate();
		ENGINE_MANAGER->Create("Failed to construct window %s (%i, %i)", title, width, height);
		return;
	}

	glfwMakeContextCurrent(m_Window);
	if (glewInit() != GLEW_OK) {
		ENGINE_MANAGER->Create("Failed to initiliaze GLEW!");
	}
}

Window::~Window() {
	if (m_Window == nullptr)
		return;

	glfwDestroyWindow(m_Window);
	glfwTerminate();
}

GLFWwindow* Window::GetWindow() {
	return m_Window;
}