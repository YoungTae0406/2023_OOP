#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
double min_value(T x) { // 재귀호출의 종료함수
	return x;
}

template<typename T, typename... Args>
double min_value(T x, Args... args) {
	// 재귀적으로 호출하여 가장 작은 값을 리턴한다. 
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
