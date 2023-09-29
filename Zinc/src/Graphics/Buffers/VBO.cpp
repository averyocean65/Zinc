#include "VBO.h"

void VBO::Generate() {
	glGenBuffers(1, &m_Id);
}

void VBO::Delete() {
	glDeleteBuffers(1, &m_Id);
}

void VBO::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void VBO::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}