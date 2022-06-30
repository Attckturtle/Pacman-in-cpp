#pragma once
#include "main.h"
class entity
{
	Type type;
	Pos pos;
	Move nextMove;
	bool detected;
	int viewRange[5][5];
public:
	entity(Type type, Pos pos);
	void death();
	void end();
	void move();
	bool onCollisionCourse();
	bool detect();
	void runAway();
};

