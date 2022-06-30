#include "main.h"
#include "entity.h"
const int boxHeight = 35;
const int boxWidth = 35;
int box[boxWidth][boxHeight];
bool dead = false;

void generateWalls() {

}

void clearScreen()
{
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void draw() {
	clearScreen();
	for(int j = 0; j < boxWidth + 2; j++) std::cout << "||";

	for (int i = 0; i < boxHeight; i++) {
		std::cout << "\n||";
		for (int j = 0; j < boxWidth; j++) {
			bool isPacman = false;

			if (!isPacman) {
				if (pacman.x == j && pacman.y == i) std::cout << "PP";
				else if (box[i][j] == Type::VWALL) std::cout << "||";
				else if (box[i][j] == Type::HWALL) std::cout << "--";
				else std::cout << "  ";
			}
		}
		std::cout << "||";
	}

	std::cout << "\n";
	for (int j = 0; j < boxWidth + 2; j++) std::cout << "||";
}

int main() {
	pacman = { rand() % boxWidth, rand() % boxHeight };
	for (int i = 0; i < boxWidth; i++)
		for (int j = 0; j < boxHeight; j++)
			box[boxWidth - 1][boxHeight - 1] = Type::EMPTY;

	while (!dead) {
		update();
		draw();
		for (int i = 0; i < boxWidth; i++) {
			for (int j = 0; j < boxHeight; j++) {
				if (box[i][j] == Type::PACMAN && box[i][j] == Type::GHOST) {
					dead = true;
					break;
				}
			}
		}
		Sleep(100);
	}
}