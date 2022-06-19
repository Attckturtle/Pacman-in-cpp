#pragma once

#include<iostream>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<cstdlib>

#include"Pos.h"

void update();
void clearScreen();

enum Move {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum Type {
	EMPTY,
	VWALL,
	HWALL,
	TP,
	PACMAN,
	GHOST,
	PELLET,
	FRUIT
};

extern const int boxHeight,boxWidth;

extern int score;

extern int box[50][50];

extern Pos pacman;

extern char lastKey;
