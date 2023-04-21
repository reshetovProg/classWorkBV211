#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

const int SPEED = 100;
const int SIZE_FIELD = 10;
const int MARGIN = 5;
const int MIN_SIZE_SNAKE = 3;
