#include <windows.h>
#include <iostream>
#include <random>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>
#include <vector>
#include <iomanip>
#include "Cursor.h"
#include "Decorator.h"
#include <cstdlib>
void printString(int i);
void eraseString(int i);
void input(int c);
void strCompare();

std::string userInput;
std::vector<MyString> v;
int MAXWIDTH = 16;
int END = 0;
bool isGameStart = true;
bool isAllYPass = false;

void printString(int i) { // ȭ�鿡 ���ڿ� ����ϴ� �Լ�
	Cursor::gotoxy(v[i].x, v[i].y);
	std::cout << v[i].word;
}

void eraseString(int i) { // ȭ�鿡�� ���ڿ��� ����� �Լ�
	if (v[i].isPrint) { // ȭ�鿡 ���ڿ��� ��µǾ��ִٸ�
		Cursor::gotoxy(v[i].x, v[i].y);
		for (int i = 0; i < MAXWIDTH-1; i++) {
			std::cout << " "; // �����
		}
	}
}
void input(int c) { // ����� �Է°� ���õ� ���� �Լ���.
	if (c == '\b') { // �齺���̽� ������
		if (userInput.length() != 0) {
			Cursor::gotoxy(6 + userInput.length() - 1, 23);
			std::cout << " ";
			userInput.pop_back();
		}
	}
	else if (c != '\r') { // ����Ű ������ �ٸ� Ű
		Cursor::gotoxy(6 + userInput.length(), 23);
		printf("%c", c);
		userInput.push_back(c);
	}
	else if (c == '\r') { // ���� Ű
		strCompare();
		Cursor::gotoxy(6, 23);
		for (int i = 0; i < userInput.length(); i++)
			std::cout << " ";
		userInput.clear();
		//ending();
	}
}
void strCompare() { // ����ڰ� �Է��� ���ڿ��� �ǰ� Ÿ���εƴ��� Ȯ��
	for (int i = 0; i < v.size(); i++) {
		if (userInput.compare(v[i].word) == 0) { // ���ڿ��� ������
			v[i].isCorrect = true; // �°� Ÿ���� �� ���¸� ����.
			eraseString(i);
			v[i].word = "";
		}
	}
}
void setRandomX() { // x���� 5��� �� ���ڿ��� ������ ��ġ�� ����� ������.
	for (int i = 0; i < v.size(); i++) {
		int temp = rand() % 5 + 1;
		if (temp == 1) {
			int rx = MAXWIDTH/2; // 16/2
			v[i].x = rx;
		}
		else if (temp == 2) {
			int rx = MAXWIDTH + MAXWIDTH/2;
			v[i].x = rx;
		}
		else if (temp == 3) {
			int rx = 2*MAXWIDTH + MAXWIDTH/2;
			v[i].x = rx;
		}
		else if (temp==4){
			int rx = 3*MAXWIDTH + MAXWIDTH/2;
			v[i].x = rx;
		}
		else {
			int rx = 4 * MAXWIDTH + MAXWIDTH / 2;
			v[i].x = rx;
		}
	}
}
void drawBorder() { // ��輱 �׸� �Լ�
	Cursor::gotoxy(0, 21);
	std::cout << "---------------------------------------------------------------------------------------------\n\n";
	std::cout << "�Է�: ";

}
bool whenGameEnd() { // ������ ���������� Ȯ��
	int count = v.size();
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].isPrint) {
			count--;
		}
	}
	if (count == 0) {
		isAllYPass = true;
	}
	return isAllYPass;
}

void randomSpeed() { // �ϰ��ϴ� �ӵ��� �ֱ������� �����ϰ� �����ϴ� �Լ�
	if (END % 5 == 0) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].y > 0) {
				int rs = rand()%5 + 1;
				v[i].speed = rs;
			}
			
		}
	}
}
void gameEnd() { // ������ ������ ��� ������� Ȯ���ϴ� �Լ�
	int c = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].isCorrect) {
			c++;
		}
	}
	Cursor::gotoxy(0, 0);
	std::cout << "##########\n";
	std::cout << "���� : " << c << "/ 20\n";
	std::cout << "##########";
}
bool setWindowSize(int width, int height) { // ������� �ܼ�â�� ���������� �����ϴ� �Լ�
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize;
	windowSize.Left = 0;
	windowSize.Top = 0;
	windowSize.Right = width - 1; // �ʺ�
	windowSize.Bottom = height - 1; // ����

	return SetConsoleWindowInfo(hStdout, TRUE, &windowSize);
}

int main() {
	Cursor::hideCursor();	// Ŀ�� �����
	setWindowSize(120, 30); // 120, 30 ���� �ܼ�â ����.

	//std::vector<MyString> v;
	srand(static_cast<unsigned int>(time(0)));
    int choice;
    RandomStringComponent* generator = new BasicString(); // Decorator.h �� generator 
	
    std::cout << "Ÿ�ڰ����� �����մϴ�." << std::endl;
	std::cout << "�� 20���� �ܾ ���ɴϴ�." << std::endl;
	std::cout << "20���� ������ ������ ����Ǹ� ������ ���ɴϴ�." << std::endl;
    std::cout << "�ɼ��� �������ּ��� \n1. Alphabet\n2. Number\n3. SpecialChar\n" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        generator = new AlphabetDecorator(generator);
        break;
    case 2:
        generator = new NumberDecorator(generator);
        break;
    case 3:
        generator = new SpecialDecorator(generator);
        break;
    default:
        std::cout << "1, 2, 3 �� �Է��Ͽ� �ɼ��� �����ؾ��մϴ�.\n";
        return 1;
    }

	for (int i = 0; i < 20; i++) { // ������ ���ڿ��� ���Ϳ� �ֱ�
		std::string temp = generator->getRandomString();
		v.push_back(MyString(temp));
	}
	setRandomX();

	system("cls"); 
	int c;
	clock_t time1 = clock();
	int count = 1;
	while (isGameStart) { // ���� ����
		if (_kbhit()) {
			c = _getch();
			input(c);
		}
		if (clock() - time1 > 2000) { // 2�ʸ��� ���ڿ� ������ ��
			for (int i = 0; i < count; i++) {
				drawBorder();
				randomSpeed();
				eraseString(i);
				v[i].y += v[i].speed; // �ֱ������� �ٲ�� �ӵ��� �ݿ�
				if (v[i].y >= 21) { // ��輱�� �Ѿ���� ���� ó��
					v[i].isPrint = false;
					v[i].word = "";
					eraseString(i);
				}
				else {				
					printString(i);
					if (v[i].y == 0) { // �ֻ�ܿ� ���ڿ� ����ϱ����� ���� �� speed�� �ֱ�
						v[i].speed = 1;
					}
				}
				
			}
			if (count < 20) {
				count++;
			}
			time1 = clock();
		}
		END++;
		if (whenGameEnd()) {
			isGameStart = false;
		}
	}
	gameEnd();

    return 0;
}