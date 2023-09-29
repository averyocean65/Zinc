#pragma once
#include "BufferBase.h"

class IBO : public BufferBase
{
public:
	IBO()
		: BufferBase() { }

	void Bind() const override;
	void Unbind() const override;

protected:
	void Generate() override;
	void Delete() override;
};