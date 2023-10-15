#include <iostream>
#include <string>
using namespace std;
class Circle {
	const double PI = 3.14;
	double radius; // ������
	double cir, area; // �ѷ�, ����
	static int count; // ���� ����
public:	Circle() : radius{ 0.0 }, cir{ 0.0 }, area{ 0.0 } {		count++;	}	Circle(double r) {		count++;		this->radius = r;		this->cir = r * 2 * 3.14;		this->area = r * r * 3.14;	}	void printCircle() {
		cout << "���� ������ : " << radius << endl;
		cout << "���� �ѷ� : " << cir << endl;
		cout << "���� ���� : " << area << endl;
		cout << "���ݱ��� ������ ���� ���� = " << Circle::count << endl <<
			endl;
	}
};

int Circle::count = 0;
int main()
{
	Circle c1;
	c1.printCircle();

	Circle c2(3);
	c2.printCircle();

	Circle c3(5.5);
	c3.printCircle();

	return 0;
}