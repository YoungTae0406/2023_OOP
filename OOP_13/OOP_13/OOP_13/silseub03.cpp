#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto i = first; i != last; i++) { //�������� �ݺ���
		for (auto j = std::next(i); j != last; j++) {
			if (comp(*i, *j)) { // Functor ����
				auto temp = *i; // ���� ������.
				*i = *j;
				*j = temp;
			}
		}
	}
	// bubble sort ���� ����
}
class compGreater { // �������� ���Ŀ� ���
public:
	bool operator()(double a, double b) { return a > b ? true : false; }
	// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
};
class compLess { // �������� ���Ŀ� ���
public:
	bool operator()(double a, double b) { return a > b ? false : true; }
	// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
	std::cout << "�������� ����" << std::endl;
	// bubble sort ����Ͽ� �������� ���� �� ��� ���
	bubble_sort(values.begin(), values.end(), compGreater());
	for (auto v : values) std::cout << v << " ";

	std::cout << std::endl;
	std::cout << "�������� ����" << std::endl;
	bubble_sort(values.begin(), values.end(), compLess());
	// bubble sort ����Ͽ� �������� ���� �� ��� ���
	for (auto v : values) std::cout << v << " ";
	std::cout << std::endl;
	return 0;
}