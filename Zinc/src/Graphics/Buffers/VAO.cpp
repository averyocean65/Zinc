#include "VAO.h"

void VAO::Generate() {
	glGenVertexArrays(1, &m_Id);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &m_Id);
}

void VAO::Bind() const {
	glBindVertexArray(m_Id);
}

void VAO::Unbind() const {
	glBindVertexArray(0);
}