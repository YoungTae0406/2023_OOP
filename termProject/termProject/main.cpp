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
#include <mutex>

const int WIDTH = 80;
const int HEIGHT = 15;
bool isGameRunning = true;
static int thr_exit = 0;
std::thread inputThread;
std::string inputBuffer;
std::mutex mtx;

class MyString {
public:
	int x;
	std::string word;
	int speed;
	MyString() {}

	MyString(std::string& w) : word(w) { this->x = 0; this->speed = 1; }

	void setX(int p) { // x축 위치 설정
		this->x = p;
	}
	void setSpeed(int p) {
		this->speed = p;
	}

};

class RandomStringComponent {
public:
	virtual std::string getRandomString() = 0;
	virtual ~RandomStringComponent() {

	}
};

class BasicString : public RandomStringComponent {
public:
	std::string getRandomString() override {
		std::string a;
		a = "aaaaabbbbb";
		return a;
	}

};

class StringDecorator : public RandomStringComponent {
protected:
	RandomStringComponent* RSC;
public:
	StringDecorator(RandomStringComponent* rsc) : RSC(rsc) {}
	std::string getRandomString() override {
		return RSC->getRandomString();
	}
	virtual ~StringDecorator() {
		delete RSC;
	}

};

class AlphabetDecorator : public StringDecorator {
public:
	AlphabetDecorator(RandomStringComponent* rsc) : StringDecorator(rsc) {}
	std::string getRandomString() override {

		std::string charset = "abcdefghijklmnopqrstuvwxyz";
		std::string result = StringDecorator::getRandomString();
		for (int i = 0; i < 10; i++) {
			int index = rand() % charset.size();
			result[i] = charset[index];
		}

		return result;
	}

};

class NumberDecorator : public StringDecorator {
public:
	NumberDecorator(RandomStringComponent* rsc) : StringDecorator(rsc) {}
	std::string getRandomString() override {

		std::string charset = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::string result = StringDecorator::getRandomString();
		for (int i = 0; i < 10; i++) {
			int index = rand() % charset.size();
			result[i] = charset[index];
		}

		return result;
	}

};
class SpecialDecorator : public StringDecorator {
public:
	SpecialDecorator(RandomStringComponent* rsc) : StringDecorator(rsc) {}
	std::string getRandomString() override {
		
		std::string charset = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
		std::string result = StringDecorator::getRandomString();
		for (int i = 0; i < 10; i++) {
			int index = rand() % charset.size();
			result[i] = charset[index];
		}

		return result;
	}
};

void printScreen(std::vector<MyString>& v) {

	system("cls");

	for (int i = 0; i < v.size(); ++i) {
		std::cout << std::setw(v[i].x) << "" << v[i].word << std::endl;
		
	}
	std::cout << "-------------------------------------\n";
	std::cout << "입력 : " << inputBuffer << std::flush;
}

void downWord(std::vector<MyString>& v) {
	for (int i = v.size()-1; i > 0; i--) {
		v[i].word = v[i - 1].word;
		v[i].x = v[i - 1].x;
		v[i - 1].x = 0;
		v[i - 1].word = " ";

		
	}
	
}

void processInput() {
	while (!thr_exit) {
		
		char ch = getchar();
		if (ch == '\n') {
			inputBuffer.clear();
		}
		else {
			inputBuffer += ch;
		}


	}
}
void start_thread() {
	thr_exit = 0;
	inputThread = std::thread(processInput);
	inputThread.detach();
}
void end_thread() {
	thr_exit = 1;
	if (inputThread.joinable()) {
		inputThread.join();
	}
	
}

std::vector<MyString> v;

int main() {
	srand(static_cast<unsigned int>(time(0)));
    int choice;
    RandomStringComponent* generator = new BasicString();
	
    // 내 컴퓨터 콘솔창 크기. 세로 30, 가로 120
	// 5등분 각각 24칸을 차지.
    
    std::cout << "타자게임을 시작합니다." << std::endl;
    std::cout << "옵션을 선택해주세요 \n1. Alphabet\n2. Number\n3. SpecialChar\n" << std::endl;
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
        std::cout << "1, 2, 3 을 입력하여 옵션을 선택해야합니다.\n";
        return 1;
    }
    
	for (int i = 0; i < 20; i++) {
		std::string temp = generator->getRandomString();
		v.push_back(MyString(temp));
	}
	
	//std::thread screenThread(printScreen, std::ref(v));
	start_thread();
	
	while (true) {
		Sleep(1000);
		downWord(v);
		printScreen(v);
	}


	//screenThread.join();
	end_thread();
	
	
	
	

    return 0;
}