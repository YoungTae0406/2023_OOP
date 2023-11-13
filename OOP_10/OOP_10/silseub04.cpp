#include <iostream>
using namespace std;
class BaseClass {
public:
	virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass{
	
};

int main() {
	BaseClass* base = new DerivedClass(); // BaseClass Ÿ���� �����͸� �����ϰ� 
	//DerivedClass ��ü�� �Ҵ���
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
	// dynamic cast�� ����� base�� �ٿ�ĳ������.

	if (derived) { // dynamic_cast�� ����� �̷������ �ʾҴٸ� nullptr�� ��ȯ��
		cout << "Everything is OKAY\n";
	}
	else {
		cout << "Fail\n";
	}

	delete base; //new�� ��������� �޸� ������.

	return 0;
}