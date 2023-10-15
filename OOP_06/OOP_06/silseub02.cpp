#include <iostream>
#include <exception>
using namespace std;

class dividedByZero : public exception{ //exception을 상속받는 새로운 exception
public:
	const char* what() { // overriding할 함수 어떤 에러인지 리턴함
		return "Unknown Exception";
	}
};

int main() {
	try {
		throw dividedByZero(); // throw로 에러를 일으킴

	}
	catch (exception& e) { // 에러를 e 변수로 받음
		cout << "My exception is " << e.what() << endl;
	}
	return 0;
}