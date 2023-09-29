#pragma once
#include "BufferBase.h"

class VAO : public BufferBase
{
public:
	VAO()
		: BufferBase() { }

	void Bind() const override;
	void Unbind() const override;

protected:
	void Generate() override;
	void Delete() override;
};