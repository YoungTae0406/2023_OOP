#include <iostream>
#include <cassert>

class CEO {
public:
	virtual ~CEO() {}
};
class CPO {
public:
	virtual ~CPO() {}

};
class Manager : public CEO, public CPO{
public:
	virtual ~Manager() {}
};
class Staff : public Manager {
public:

};

int main() {
	CPO* cpo = new Staff(); // Staff 객체를 생성하고 업캐스팅한다.
	CEO* ceo = new Staff(); // Staff 객체를 생성하고 업캐스팅한다. 
	Staff* staff = dynamic_cast<Staff*>(cpo); // CPO* 타입인 cpo를 Staff* 타입으로 downcasting
	Staff* staff2 = dynamic_cast<Staff*>(ceo); // ceo를 Staff* 타입으로 downcasting
	Manager* manager = dynamic_cast<Manager*>(cpo);

	assert(staff != nullptr); // false가 되면 프로그램을 중단시키고 에러 로그를 띄워줌
	assert(staff2 != nullptr);
	assert(manager != nullptr);

	delete cpo; // 메모리 누수 관리
	delete ceo;

	return 0;
}

