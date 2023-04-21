#include "param.h"

char** createField(int size) {
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
		for (int j = 0; j < size; j++) {
			field[i][j] = '~';
		}
	}
	return field;
}

int** createSnake(int size) {
	int** snake = new int* [size];
	for (int i = 0; i < size; i++) {
		snake[i] = new int[2];
	}
	return snake;

}

char keyboard() {
	char s;
	while (true) {
		if (_kbhit()) {
			s = _getch();
			return s;
		}
		else return ' ';
	}
}

void render(char** field, int** snake, int* fruit) {
	system("cls");

	int sizeField = _msize(field) / sizeof(field[0]);
	for (int i = 0; i < sizeField; i++) {
		for (int j = 0; j < sizeField; j++) {
			field[i][j] = '~';
		}
	}
	for (int i = 0; i < MARGIN; i++) cout << endl;

	int size = _msize(field[0]);
	int sizeSnake = _msize(snake) / sizeof(snake[0]);

	field[snake[0][0]][snake[0][1]] = char(2);
	for (int i = 1; i < sizeSnake; i++) {
		field[snake[i][0]][snake[i][1]]='o';
	}

	field[fruit[0]][fruit[1]] = char(253);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < MARGIN; j++) cout << "  ";
		for (int j = 0; j < size; j++) {
			cout << field[i][j]<< " ";
		}
		cout << endl;
	}

}

void setPosition(int** snake, int y, int x) {
	int size = _msize(snake) / sizeof(snake[0]);
	for (int i = 0; i < size; i++, y++) {
		snake[i][0] = y;
		snake[i][1] = x;
	}
}

void setPosition(int* fruit, int y, int x) {
	fruit[0] = y;
	fruit[1] = x;
}

bool gameOver(int** snake) {
	int size = _msize(snake) / sizeof(snake[0]);
	for (int i = 1; i < size; i++) {
		if (snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1]) {
			return true;
		}
	}
	return false;
}

bool unions(int** snake, int* fruit) {
	int size = _msize(snake) / sizeof(snake[0]);
	for (int i = 0; i < size; i++) {
		if (snake[i][0] == fruit[0] && snake[i][1] == fruit[1]) {
			return false;
		}
	}
	return true;
}

void push(int**& snake, int* oldTail) {
	int size = _msize(snake) / sizeof(snake[0]);
	int** buf = new int*[size + 1];
	for (int i = 0; i < size; i++) {
		buf[i] = snake[i];
	}
	buf[size] = new int[2]{ oldTail[0], oldTail[1] };
	delete[] snake;
	snake = buf;

}

bool eat(int**& snake, int* fruit, int* oldTail) {
	if (!unions(snake, fruit)) {
		push(snake, oldTail);
		return true;
	}
	return false;
}

int* step(int** snake, char& side, char& oldS) {
	int size = _msize(snake) / sizeof(snake[0]);
	int* oldTail = new int[2]{snake[size-1][0],snake[size - 1][1] };
	if (oldS == 'w' && side == 's' ||
		oldS == 's' && side == 'w' ||
		oldS == 'a' && side == 'd' ||
		oldS == 'd' && side == 'a') {
		side = oldS;
	}

	


	switch (side) {
	case 'w':
		//дописать условие и отсавшиеся направления
		
			for (int i = size - 1; i > 0; i--) {
				swap(snake[i], snake[i - 1]);
			}
			if (snake[1][0] == 0) {
				snake[0][0] = SIZE_FIELD - 1; //y
			}
			else snake[0][0] = snake[1][0] - 1; //y
			snake[0][1] = snake[1][1]; //x
			
		break;
	case 's':
		
			for (int i = size - 1; i > 0; i--) {
				swap(snake[i], snake[i - 1]);
			}
			if (snake[1][0] == SIZE_FIELD-1) {
				snake[0][0] = 0; //y
			}
			else snake[0][0] = snake[1][0] + 1; //y
			snake[0][1] = snake[1][1]; //x
					
		break;
	case 'a':
		
			for (int i = size - 1; i > 0; i--) {
				swap(snake[i], snake[i - 1]);
			}
			if (snake[1][1] == 0) {
				snake[0][1] = SIZE_FIELD - 1; //x
			}
			else snake[0][1] = snake[1][1] - 1; //y
			snake[0][0] = snake[1][0]; //x
			
		
		break;
	case 'd':
		
			for (int i = size - 1; i > 0; i--) {
				swap(snake[i], snake[i - 1]);
			}
			if (snake[1][1] == SIZE_FIELD - 1) {
				snake[0][1] = 0; //x
			}
			else snake[0][1] = snake[1][1] + 1; //x
			snake[0][0] = snake[1][0]; //y
			
		
		break;
	default:
		side = oldS;
		break;
	}
	oldS = side;
	return oldTail;
	

}

int main()
{
	//commit2
	srand(time(NULL));
	//создание объектов
	char** field = createField(SIZE_FIELD);
	int** snake = createSnake(MIN_SIZE_SNAKE);
	int* fruit = new int[2];

	//выставление первоначальных позиций
	setPosition(snake, SIZE_FIELD / 2, SIZE_FIELD / 2);
	do {
		setPosition(fruit, random(0, SIZE_FIELD - 1), random(0, SIZE_FIELD - 1));
	} while (!unions(snake, fruit));

	//отрисовка
	render(field, snake, fruit);
	int* oldTail = nullptr;
	char s='w';
	char buf;
	char oldS=s;
	while (true) {
		Sleep(SPEED);
		buf = keyboard();
		if (buf != ' ') s = buf;
		delete[]oldTail;
		oldTail = step(snake, s, oldS);
		if (eat(snake, fruit, oldTail)) {
			do {
				setPosition(fruit, random(0, SIZE_FIELD - 1), random(0, SIZE_FIELD - 1));
			} while (!unions(snake, fruit));
		}
		if (gameOver(snake)) {
			system("cls");
			cout << "GAME OVER";
			break;

		}
		render(field, snake, fruit);

	}

}
