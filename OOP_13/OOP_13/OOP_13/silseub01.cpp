#include <iostream>

template <typename T> 
auto sum(T arg) { // ����� �������ǿ� �ش��Ѵ�.
	return arg;
} 

template <typename T, typename... Types>
auto sum(T arg, Types... args) { // �������ڸ� �޴� �Լ�
	// ��͸� ���� args�� �ϳ��� �ٰԵǰ� 
	// �������ǿ� �ٴٸ��� �Ǹ� ���� �Լ��� ȣ��ȴ�. �ű⼭���� ���� +�� �ذ��鼭
	// �� ���� ���� �� �ְ� �ȴ�.
	return arg + sum(args...);
} 

template <typename T, typename... Types>
float average(T arg, Types... args) { // �������ڸ� �޾� ����� ����ϴ� �Լ�
	float result = 0.0; // �� ��
	result = sum(arg, args...);
	return result / (sizeof...(args) + 1);

} 

int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5

	return 0;
}
