#include "Zinc/Entry.h"
#include "ZincCore.h"
#include "Zinc/Events/KeyEvent.h"

#include "Window/Window.h"
#include "Vert.h"
#include "Shader.h"

#include "Buffers/VAO.h"
#include "Buffers/VBO.h"
#include "Buffers/IBO.h"

/// <summary>
/// Prints an event using event.ToString()
/// </summary>
/// <param name="e">The event</param>
void printEvent(Event& e) {
	APP_LOGGER->ok("EVENT: %s", e.ToString().c_str());
}

int appMain(int argc, char** argv) {
	APP_LOGGER->info("Initialized App!");

	// Create dispatcher
	EventDispatcher dispatcher;

	// Create events
	KeyPressedEvent pressed(0xFF);
	KeyReleasedEvent released(0xAA);
	Event other;

	// Subscribers
	dispatcher.Subscribe(EventType::KeyPressed, printEvent);
	dispatcher.Subscribe(EventType::KeyReleased, printEvent);
	dispatcher.Subscribe(EventType::Unknown, printEvent);

	// Dispatch events
	dispatcher.Dispatch(pressed);
	dispatcher.Dispatch(released);
	dispatcher.Dispatch(other);

	Window win("Test Window", 640, 480);
	GLFWwindow* glWindow = win.GetWindow();

	Shader myShader("Vert.glsl", "Frag.glsl");

	// Vertices
	Vert vertices[] =
	{
		glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.f, 1.f),
		glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.f, 0.f),
		glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(1.f, 0.f),
		glm::vec3(0.5f, 0.5f, 0.0f), glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(1.f, 1.f)
	};

	// Number of vertices
	unsigned nrOfVertices = sizeof(vertices) / sizeof(Vert);

	// Indices
	GLuint indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	// Number of indices
	unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

	VAO vao;
	VBO vbo;
	IBO ibo;

	vao.Bind();
	vbo.Bind();
	ibo.Bind();

	// Pushes the vertex and index data into opengl's buffers
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Sets up position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vert), (void*)0);
	glEnableVertexAttribArray(0);

	// Sets up the color and texture coordinates
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	//glEnableVertexAttribArray(2);

	ibo.Unbind();
	vbo.Unbind();
	vao.Unbind();

	while (!glfwWindowShouldClose(glWindow)) {
		glClearColor(.12f, .12f, .12f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		myShader.Use();
		vao.Bind();
		myShader.Draw(nrOfIndices, indices);
		myShader.Unuse();

		glfwSwapBuffers(glWindow);
		glfwPollEvents();
	}

	return ZINC_SUCCESS;
}