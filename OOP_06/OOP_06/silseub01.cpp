#include <iostream>
using namespace std;
class temp { //operator overloading�� ������ Ŭ����
public:
	int x; // overloading ���� ������ų int�� ����
	temp() : x(5) {} // �ʱⰪ�� �ֱ� ���� ������

	temp& operator++() { // ���� 
		x++;
		return *this;
	}
	temp operator++(int) { // ����
		temp t = *this;
		x++;
		return t;
	}
};


void main() {
	temp a;
	cout << "�ʱⰪ: " << a.x << "\n";
	a++;
	cout << "a++ ���: "<< a.x << "\n";
	++a;
	cout << "++a ���: " << a.x << "\n";


}