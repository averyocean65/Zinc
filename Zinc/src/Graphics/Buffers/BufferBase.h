#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class BufferBase
{
public:
	BufferBase() { Generate(); }
	virtual ~BufferBase() { Delete(); }

	virtual void Bind() const { }
	virtual void Unbind() const { }

protected:
	virtual void Generate() { }
	virtual void Delete() { }

	unsigned int m_Id;
};