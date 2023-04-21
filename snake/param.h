#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int* step(int** snake, char& side, char& oldS);
bool eat(int**& snake, int* fruit, int* oldTail);
void push(int**& snake, int* oldTail);
bool unions(int** snake, int* fruit);
bool gameOver(int** snake);
void setPosition(int* fruit, int y, int x);
void setPosition(int** snake, int y, int x);
void render(char** field, int** snake, int* fruit);
char keyboard();
int** createSnake(int size);
char** createField(int size);

#define random(a,b) a+rand()%(b+1-a)

const int SPEED = 100;
const int SIZE_FIELD = 10;
const int MARGIN = 5;
const int MIN_SIZE_SNAKE = 3;
