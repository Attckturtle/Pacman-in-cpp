#include "main.h"

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
}