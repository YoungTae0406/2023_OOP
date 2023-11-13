#include <iostream>
class Parent {
	char* p;
public:
	Parent() {
		p = new char[10];
		std::cout << "Parent Constructor invocation" << std::endl;
	}
	virtual ~Parent() {
		delete[] p;
		std::cout << "Parent Destructor invocation" << std::endl;
	}
};

class Child : public Parent {
	char* c;
public:
	Child() : Parent() {
		c = new char[10];
		std::cout << "Child Constructor invocation" << std::endl;
	}
	~Child() {
		delete[] c;
		std::cout << "Child Destructor invocation" << std::endl;
	}
};

int main() {
	std::cout << "--- Case1: Normal Child instantiation ---" << std::endl;
	Child* c = new Child();
	delete c;

	std::cout << "--- Case2: Parent pointer to Child ---" << std::endl;
	Parent* p = new Child();
	delete p;

	getchar();
}
// 문제점은 upcasting일때 p가 생명주기가 다 돼서 소멸하게 되면
// 소멸자가 호출되는데 이때 기반 클래스의 소멸자가 호출돼서 child의 소멸자는 
// 호출되지 않아 메모리 누수가 발생하게 됨.
// 해결방법은 기반 클래스의 소멸자에 virtual을 붙여준다.