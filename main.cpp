#include "main.h"
#include "entity.h"

void draw() {

}

int main() {
	for (int i = 0; i < boxWidth; i++)
		for (int j = 0; j < boxHeight; j++)
			box[boxWidth][boxHeight] = Type::EMPTY;

	while (true) {
		update();
		draw();
	}
}