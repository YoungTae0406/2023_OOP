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
	CPO* cpo = new Staff(); // Staff ��ü�� �����ϰ� ��ĳ�����Ѵ�.
	CEO* ceo = new Staff(); // Staff ��ü�� �����ϰ� ��ĳ�����Ѵ�. 
	Staff* staff = dynamic_cast<Staff*>(cpo); // CPO* Ÿ���� cpo�� Staff* Ÿ������ downcasting
	Staff* staff2 = dynamic_cast<Staff*>(ceo); // ceo�� Staff* Ÿ������ downcasting
	Manager* manager = dynamic_cast<Manager*>(cpo);

	assert(staff != nullptr); // false�� �Ǹ� ���α׷��� �ߴܽ�Ű�� ���� �α׸� �����
	assert(staff2 != nullptr);
	assert(manager != nullptr);

	delete cpo; // �޸� ���� ����
	delete ceo;

	return 0;
}

