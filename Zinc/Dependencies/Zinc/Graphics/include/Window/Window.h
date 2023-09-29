#pragma once
#include "ZincCore.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Window
{
public:
	Window() = delete;
	Window(const char* title, int width, int height);
	~Window();

	GLFWwindow* GetWindow();

private:
	GLFWwindow* m_Window;
};