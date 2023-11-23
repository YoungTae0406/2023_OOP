#include <windows.h>
#include <iostream>
#include <random>
#include <string>
#include <ctime>

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
		srand(static_cast<unsigned int>(time(0)));

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
		srand(static_cast<unsigned int>(time(0)));

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
		srand(static_cast<unsigned int>(time(0)));

		std::string charset = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
		std::string result = StringDecorator::getRandomString();
		for (int i = 0; i < 10; i++) {
			int index = rand() % charset.size();
			result[i] = charset[index];
		}

		return result;
	}
};

void getConsoleSize(int& columns, int& rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int main() {
    int columns, rows;
    int choice;
    RandomStringComponent* generator = new BasicString();

    getConsoleSize(columns, rows);

    std::cout << rows << "  " << columns <<"\n"; // 세로 30, 가로 120
    
    int sectionWidth = columns / 5;
    int sectionHeight = rows / 12;

    for (int i = 0; i < 5; ++i) {
        std::cout << std::string(sectionWidth - 1, '-') << "|";
    }// 가로 체크

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
    std::cout << generator->getRandomString();
    


    return 0;
}