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

void printString(int i);
void eraseString(int i);
void input(int c);
void strCompare();

std::string userInput;
std::vector<MyString> v;
int MAXWIDTH = 20;
int END = 0;

void printString(int i) {
	Cursor::gotoxy(v[i].x, v[i].y);
	std::cout << v[i].word;
}

void eraseString(int i) {
	Cursor::gotoxy(v[i].x, v[i].y);
	for (int i = 0; i < MAXWIDTH-1; i++) {
		std::cout << " ";
		
	}
}

void input(int c) {
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
void strCompare() {
	for (int i = 0; i < v.size(); i++) {
		if (userInput.compare(v[i].word) == 0) { // ���ڿ��� ������
			v[i].isCorrect = true;
			eraseString(i);
			v[i].word = "";
		}
	}
}
void setRandomX() {
	for (int i = 0; i < v.size(); i++) {
		int temp = rand() % 4 + 1;
		if (temp == 1) {
			int rx = MAXWIDTH/2;
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
		else {
			int rx = 3*MAXWIDTH + MAXWIDTH/2;
			v[i].x = rx;
		}
	}
}
void drawBorder() {
	Cursor::gotoxy(0, 21);
	std::cout << "---------------------------------------------------------------------------------------------\n\n";
	std::cout << "�Է�: ";

}
void countEnd() {
	END++;
}

int main() {
	//Cursor::hideCursor();
	//std::vector<MyString> v;
	srand(static_cast<unsigned int>(time(0)));
    int choice;
    RandomStringComponent* generator = new BasicString(); // Decorator.h
	
    // �� ��ǻ�� �ܼ�â ũ��. ���� 30, ���� 120
	// 4��� ���� 30ĭ�� ����.
    
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

	for (int i = 0; i < 20; i++) {
		std::string temp = generator->getRandomString();
		v.push_back(MyString(temp));
	}
	setRandomX();

	system("cls"); 

	int c;
	clock_t time1 = clock();
	
	int count = 1;
	
	while (1) {
		if (_kbhit()) {
			c = _getch();
			input(c);
		}
		if (clock() - time1 > 1000) {
			for (int i = 0; i < count; i++) {
				drawBorder();
				eraseString(i);
				v[i].y++;
				if (v[i].y == 21) {
					countEnd();
					v[i].word = "";
					eraseString(i);
				}
				else {
					printString(i);
					
				}
			}
			if (count < 20) {
				count++;
			}
			time1 = clock();
		}
		if (END==20) {
			break;
		}
		
	}

    return 0;
}