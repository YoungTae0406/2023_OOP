#include <iostream>
#include <exception>
using namespace std;

class dividedByZero : public exception{ //exception�� ��ӹ޴� ���ο� exception
public:
	const char* what() { // overriding�� �Լ� � �������� ������
		return "Unknown Exception";
	}
};

int main() {
	try {
		throw dividedByZero(); // throw�� ������ ����Ŵ

	}
	catch (exception& e) { // ������ e ������ ����
		cout << "My exception is " << e.what() << endl;
	}
	return 0;
}