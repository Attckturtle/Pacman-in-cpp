#pragma once

#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<cstdlib>

void update();
void clearScreen();

enum Type {
	EMPTY,
	WALL,
	TP,
	PACMAN,
	GHOST,
	PELLET,
	FRUIT
};

struct Pos {
	int x, y;
};

extern const int boxHeight = 50, boxWidth = 50;

int score;

int box[boxWidth][boxHeight];

Pos pacman;

char lastKey;
