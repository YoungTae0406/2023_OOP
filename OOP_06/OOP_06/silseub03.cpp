#include <iostream>

class A {
public:
	A() { // 생성자
		std::cout << "Constructor()" << std::endl;
	}
	~A() { // 소멸자
		std::cout << "Destructor()" << std::endl;
	}

};

int main() {
	try {
		A temp;
		throw 10; // int 타입으로 예외를 발생시킴
	}
	catch (int t) { // 그 예외를 catch함. 그 예외는 변수 t로 핸들링 가능.
		std::cout << "Catch " << t;
	}
	return 0;
}