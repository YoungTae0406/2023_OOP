#include <iostream>

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<>
void swap<std::string>(std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	::swap<int>(a, b); //swap(a,b)도 가능
	::swap<float>(c, d); //swap(c,d)도 가능
	::swap<std::string>(e, f);
	// 사용자 정의 swap을 호출하기 위해 전역 네임스페이스 :: 를 사용한다

	
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;



	return 0;
}