#include <iostream>
using namespace std;

template <typename T>
void fun(const T& x) {
	static int count = 0;
	cout << "x = " << x << " count = " << count << endl;
	++count;
	return;
}

int main()
{
	fun<int>(1);
	cout << endl;
	fun<int>(1);
	cout << endl;
	fun<double>(1.1);
	cout << endl;
	return 0;
}

//fun<int> �� �ش��ϴ� count�� fun<int>�� ȣ��ɶ��� count�� �����ϰ�
//fun<double>�� �ش��ϴ� count�� fun<double>�� ȣ��ɶ��� count�� ������.
// �� ����� ���� �� ���ø� �ν��Ͻ����� ������ static ������ ����� �� �ϴ�.
