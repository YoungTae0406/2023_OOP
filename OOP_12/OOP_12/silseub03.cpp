#include <iostream>

template <typename T, int num=5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl;
}
// 결과값은 8 왜냐면 num의 디폴트 값이 5라서 3+5
