#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n) : vector_(n, 3) {
		std::cout << "Base1 constructor\n";
	}
	
private:
	std::vector<char> vector_;
};

class Base2 {
public:
	Base2(int n) : vector_(n, 3) {
		std::cout << "Base2 constructor\n";
	}
	
private:
	std::vector<char> vector_;
};

class Derived : public Base2, Base1 {
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
		std::cout << "Derived constructor\n";
	}
	// ...
private:
	std::string str_;
	int i = 0;
};

int main() {
	Derived drv("1");
	return 0;
}

// Base1, Base2, Derived 순서로 생성자가 호출됨.
// 3.1 순서를 바꿀 경우 Base2, Base1, Derived 순서로 호출됨.