#pragma once
#include "BufferBase.h"

class VBO : public BufferBase
{
public:
	VBO()
		: BufferBase() { }

	void Bind() const override;
	void Unbind() const override;

protected:
	void Generate() override;
	void Delete() override;
};