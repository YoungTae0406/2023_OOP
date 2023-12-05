#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) { // ���ȣ���� �����Լ�
	return x;
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {
	// ��������� ȣ���Ͽ� ���� ���� ���� �����Ѵ�. 
	double result = min_value(args...); 
	if (x > result) return result;
	else return x;
}

int main() {
	auto x = min_value(42, 3.14, 11.1f, -2);
	std::cout << x;
	getchar();
	return 0;
}
