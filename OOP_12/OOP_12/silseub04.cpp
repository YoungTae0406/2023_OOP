#include <iostream>

template<typename T>
T min(T x, T y) {
	return x < y ? x : y;
}
int main() {
	int x = 3;
	int y = 2;
	double d = 2.1;
	double e = 3.3;
	std::cout << "min(x,y): " << min(x, y) << ", min(d,e): " << min(d, e) << 
		", min(d, x) : " << min(d, double(x)) << std::endl;
		return 0;
}


// 초기 코드는 int와 double 타입이 인자로 들어가있어서 오류가 생김

