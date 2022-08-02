#pragma once
#include "main.h"
#include "pathfinding.h"
class entity
{
	Type type;
	Pos pos;
	Move nextMove;
	bool detected;
	Type viewRange[5][5];
	pathfinding mapFromEntity[30][30];
public:
	entity(Type type, Pos pos);
	void death();
	void end();
	void move(bool runOrNo);
	bool onCollisionCourse();
	void detect();
};

