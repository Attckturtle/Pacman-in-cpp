#pragma once
#include "main.h"
class entity
{
	Type type;
	Pos pos;
public:
	entity(Type type, Pos pos);
	void death();
};

