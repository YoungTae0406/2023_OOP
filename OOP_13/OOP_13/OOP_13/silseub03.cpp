#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto i = first; i != last; i++) { //버블정렬 반복문
		for (auto j = std::next(i); j != last; j++) {
			if (comp(*i, *j)) { // Functor 구현
				auto temp = *i; // 스왑 구현함.
				*i = *j;
				*j = temp;
			}
		}
	}
	// bubble sort 로직 구현
}
class compGreater { // 오름차순 정렬에 사용
public:
	bool operator()(double a, double b) { return a > b ? true : false; }
	// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
};
class compLess { // 내림차순 정렬에 사용
public:
	bool operator()(double a, double b) { return a > b ? false : true; }
	// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "오름차순 정렬" << std::endl;
	// bubble sort 사용하여 오름차순 정렬 후 결과 출력
	bubble_sort(values.begin(), values.end(), compGreater());
	for (auto v : values) std::cout << v << " ";

	std::cout << std::endl;
	std::cout << "내림차순 정렬" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());
	// bubble sort 사용하여 내림차순 정렬 후 결과 출력
	for (auto v : values) std::cout << v << " ";
	std::cout << std::endl;
	return 0;
}