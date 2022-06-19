#include "main.h"
#include "entity.h"
const int boxHeight = 50;
const int boxWidth = 50;
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
	for (int i = 0; i < boxWidth; i++) {
		for (int j = 0; j < boxHeight; j++) {
			switch (box[i][j]) {
			case Type::FRUIT:
				std::cout << "F";
				break;
			case Type::GHOST:
				std::cout << "G";
				break;
			case Type::PACMAN:
				std::cout << "P";
				break;
			case Type::PELLET:
				std::cout << "O";
				break;
			case Type::VWALL:
				std::cout << "|";
				break;
			case Type::HWALL:
				std::cout << "-";
				break;
			default:
				std::cout << " ";
					
			}
		}
	}
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
		Sleep(1000);
	}
}