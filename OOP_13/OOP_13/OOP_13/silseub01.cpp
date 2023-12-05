#include <iostream>

template <typename T> 
auto sum(T arg) { // 재귀의 종료조건에 해당한다.
	return arg;
} 

template <typename T, typename... Types>
auto sum(T arg, Types... args) { // 가변인자를 받는 함수
	// 재귀를 통해 args가 하나씩 줄게되고 
	// 종료조건에 다다르게 되면 위의 함수가 호출된다. 거기서부터 이제 +를 해가면서
	// 총 합을 구할 수 있게 된다.
	return arg + sum(args...);
} 

template <typename T, typename... Types>
float average(T arg, Types... args) { // 가변인자를 받아 평균을 출력하는 함수
	float result = 0.0; // 총 합
	result = sum(arg, args...);
	return result / (sizeof...(args) + 1);

} 

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5

	return 0;
}
