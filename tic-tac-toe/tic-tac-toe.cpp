#include <iostream>
#include <Windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
int x, y;
const int rows = 3;
const int cols = 3;
char arr[rows][cols] = {};
int mycount = 0;
char sign_x = 'X';
char sign_0 = '0';
int stop = 0;
int x_0 = 0;
int y_0 = 0;
int gameOver = false;
int win_or_lose() {

	if (gameOver == false)
		return 0;
	else if (gameOver == false)
		return 1;
}

void zapovn() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			arr[i][j] = ' ';
		}
	}
}


void vivid() {
	system("cls");
	for (int i = 0; i < rows; ++i) {
		cout << " | ";
		for (int j = 0; j < cols; ++j) {
			cout << arr[i][j] << " | ";
		}
		cout << endl;
		cout << " - - - - - - -";
		cout << endl;


	}
}


void fire() {
	srand(time(NULL));

	x_0 = rand() % 10 / 2;
	y_0 = rand() % 10 / 2;






	cout << "Give a cordinat of x: ";
	cin >> x;
	cout << "Give a cordinat of y: ";
	cin >> y;


	/*ЯкщоДебіл*/
	if (x > 3 || x < 0 || y > 3 || y < 0) {
		cout << "Idiot?" << endl;
		Sleep(1000);
		mycount -= 1;
		return;
	}


	/*Перевірка для значень*/

	if (arr[x - 1][y - 1] == ' ') {
		arr[x - 1][y - 1] = sign_x;
		stop += 1;
	}
	else {
		mycount -= 1;
	}



	/*Х0*/
	cout << "X fire !" << endl;
	while (arr[x_0][y_0] != ' ' && stop != 9)
	{
		x_0 = rand() % 10 / 2;
		y_0 = rand() % 10 / 2;


	}
	if (stop == 9) {
		gameOver = true;
	}
	else {

	}
	arr[x_0][y_0] = sign_0;
	stop += 1;




}


int main() {
	setlocale(LC_ALL, "ukr");
	zapovn();

	while (!win_or_lose())
	{
		vivid();
		fire();
		vivid();
		mycount += 1;
	}

	return 0;
}