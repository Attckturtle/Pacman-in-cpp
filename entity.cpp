#include "entity.h"
entity::entity(Type type, Pos pos) {
	type = type;
	pos = pos;
}

void entity::death() {
	delete this;
}