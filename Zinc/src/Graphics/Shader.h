#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <iostream>
#include <fstream>

class Shader
{
public:
	Shader(const char* vFile, const char* fFile);
	~Shader();

	void Use();

	void Unuse();

	void Delete();

	unsigned int GetProgram();

	void Draw(unsigned int nrOfIndices, unsigned int* indices);

	void SetInt(const char* name, int value);

	void SetFloat(const char* name, float value);

	void SetVec2(const char* name, glm::fvec2);

	void SetVec3(const char* name, glm::fvec3);

	void SetVec4(const char* name, glm::fvec4);

	void SetMat3(const char* name, glm::mat3 value, bool transpose = GL_FALSE);

	void SetMat4(const char* name, glm::mat4 value, bool transpose = GL_FALSE);

	void SetView(const char* name, glm::mat3 value, bool transpose = GL_FALSE);

private:
	unsigned int m_ID;

	std::string Load(char* fileName)
	{
		std::string tmp = "";
		std::string shader = "";

		std::ifstream file;

		file.open(fileName);

		if (file.is_open())
		{
			while (std::getline(file, tmp))
			{
				shader += tmp + "\n";
			}
		}
		else
		{
			std::cout << "Loading file failed" << std::endl;
		}


		return shader;
	}

	GLuint Process(GLenum type, char* fileName)
	{
		char infoLog[512];
		GLint success;

		GLuint shader = glCreateShader(type);
		std::string str_shader = Load(fileName);
		const GLchar* loaded_shader = str_shader.c_str();
		glShaderSource(shader, 1, &loaded_shader, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "Shader Compilation Failed: " << fileName << std::endl;
			std::cout << infoLog << std::endl;

			//ENGINE_LOGGER->error("Shader Compilation Failed: %s", fileName);
			//ENGINE_LOGGER->error(infoLog);
		}

		return shader;
	}

	void Link(GLuint vertexShader, GLuint fragmentShader)
	{
		char infoLog[512];
		GLint success;

		//Creating the program
		m_ID = glCreateProgram();

		//Attatching the shaders to the program id
		glAttachShader(m_ID, vertexShader);
		glAttachShader(m_ID, fragmentShader);

		//Deleted a glLinkProgram, if it gives me an error, then I know I have to link it two times
		glLinkProgram(m_ID);

		//Telling whether or not the shader works
		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
			std::cout << "Program Linking Failed" << std::endl;
			std::cout << infoLog << std::endl;
			//ENGINE_LOGGER->error("Program Linking Failed");
			//ENGINE_LOGGER->error(infoLog);
		}

		glUseProgram(0);
	}
};