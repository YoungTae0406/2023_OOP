#include <iostream>

class A {
public:
	A() { // ������
		std::cout << "Constructor()" << std::endl;
	}
	~A() { // �Ҹ���
		std::cout << "Destructor()" << std::endl;
	}

};

int main() {
	try {
		A temp;
		throw 10; // int Ÿ������ ���ܸ� �߻���Ŵ
	}
	catch (int t) { // �� ���ܸ� catch��. �� ���ܴ� ���� t�� �ڵ鸵 ����.
		std::cout << "Catch " << t;
	}
	return 0;
}