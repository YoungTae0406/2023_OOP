#include <iostream>
using namespace std;
class BaseClass {
public:
	virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass{
	
};

int main() {
	BaseClass* base = new DerivedClass(); // BaseClass 타입의 포인터를 선언하고 
	//DerivedClass 객체를 할당함
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
	// dynamic cast를 사용해 base를 다운캐스팅함.

	if (derived) { // dynamic_cast가 제대로 이루어지지 않았다면 nullptr이 반환됨
		cout << "Everything is OKAY\n";
	}
	else {
		cout << "Fail\n";
	}

	delete base; //new로 만들었으니 메모리 해제함.

	return 0;
}