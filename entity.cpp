#include "entity.h"
#include "main.h"
entity::entity(Type type, Pos pos) {
	this->type = type;
	this->pos = pos;
}

void entity::death() {
	this->pos = {boxWidth / 2,boxHeight / 2 };
}

void entity::end() {
	delete this;
}

bool entity::onCollisionCourse() {
	switch (nextMove) {
	case UP:
		if (box[pos.x][pos.y--] != Type::VWALL && box[pos.x][pos.y--] != Type::HWALL) {
			return false;
		}
		break;
	case DOWN:
		if (box[pos.x][pos.y++] != Type::VWALL && box[pos.x][pos.y++] != Type::HWALL) {
			return false;
		}
		break;
	case LEFT:
		if (box[pos.x--][pos.y] != Type::VWALL && box[pos.x--][pos.y] != Type::HWALL) {
			return false;
		}
		break;
	case RIGHT:
		if (box[pos.x++][pos.y] != Type::VWALL && box[pos.x++][pos.y] != Type::HWALL) {
			return false;
		}
		break;
	default:
		return true;
	}
}

void entity::move() {
	if (onCollisionCourse()) {
		if (box[pos.x++][pos.y] != Type::VWALL && box[pos.x++][pos.y] != Type::HWALL) {
			nextMove = Move::RIGHT;
		}
		else if (box[pos.x--][pos.y] != Type::VWALL && box[pos.x--][pos.y] != Type::HWALL) {
			nextMove = Move::LEFT;
		}
		else if (box[pos.x][pos.y++] != Type::VWALL && box[pos.x][pos.y++] != Type::HWALL) {
			nextMove = Move::DOWN;
		}
		else if (box[pos.x][pos.y--] != Type::VWALL && box[pos.x][pos.y--] != Type::HWALL) {
			nextMove = Move::UP;
		}
	}
	if (nextMove != NULL && !onCollisionCourse()) {
		switch (nextMove) {
		case UP:
			pos.y--;
			break;
		case DOWN:
			pos.y++;
			break;
		case LEFT:
			pos.x--;
			break;
		case RIGHT:
			pos.x++;
			break;
		}
	}
	else {
		this->move();
	}
}

bool entity::detect() {
	if (box[this->pos.x][this->pos.y] == )
}