#include "Buffers.h"

///VAO

//Gens the vertex arrays
VAO::VAO()
{
    glGenVertexArrays(1, &m_ID);
}

//Deletes the vertex arrays
VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_ID);
}

//Binds the vertex arrays
void VAO::Bind() const
{
    glBindVertexArray(m_ID);
}

//Unbinds the vertex arrays
void VAO::Unbind() const
{
    glBindVertexArray(0);
}

/// VBO

//Gens the buffers
VBO::VBO()
{
    glGenBuffers(1, &m_ID);
}

//Deletes the buffers
VBO::~VBO()
{
    glDeleteBuffers(1, &m_ID);
}

//Binds the buffers
void VBO::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

//Unbinds the buffers
void VBO::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/// IBO

//Gens the buffers
IBO::IBO()
{
    glGenBuffers(1, &m_ID);
}

//Deletes the buffers
IBO::~IBO()
{
    glDeleteBuffers(1, &m_ID);
}

//Binds the buffers
void IBO::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

//Unbinds the buffers
void IBO::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}