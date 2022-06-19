#include "main.h"

Pos pacman;

char lastKey;


void update() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
		case 'W':
			if (lastKey != 's') lastKey = 'w';
			break;

		case 's':
		case 'S':
			if (lastKey != 'w') lastKey = 's';
			break;

		case 'a':
		case 'A':
			if (lastKey != 'd') lastKey = 'a';
			break;

		case 'd':
		case 'D':
			if (lastKey != 'a') lastKey = 'd';
			break;
		}
	}

	switch (lastKey) {
	case 'w':
		pacman.y -= 1;
		break;
	case 's':
		pacman.y += 1;
		break;
	case 'a':
		pacman.x -= 1;
		break;
	case 'd':
		pacman.x += 1;
		break;
	}
	for (int i = 0; i < boxHeight; i++)
		for (int j = 0; j < boxWidth; j++)
			if (box[i][j] == Type::PACMAN) box[i][j] = Type::EMPTY;

	box[pacman.y][pacman.x] = Type::PACMAN;
}