#include "IBO.h"

void IBO::Generate() {
	glGenBuffers(1, &m_Id);
}

void IBO::Delete() {
	glDeleteBuffers(1, &m_Id);
}

void IBO::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}

void IBO::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}