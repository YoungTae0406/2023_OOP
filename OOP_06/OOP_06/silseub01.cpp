#include <iostream>
using namespace std;
class temp { //operator overloading을 진행할 클래스
public:
	int x; // overloading 으로 증가시킬 int형 변수
	temp() : x(5) {} // 초기값을 주기 위한 생성자

	temp& operator++() { // 전위 
		x++;
		return *this;
	}
	temp operator++(int) { // 후위
		temp t = *this;
		x++;
		return t;
	}
};


void main() {
	temp a;
	cout << "초기값: " << a.x << "\n";
	a++;
	cout << "a++ 결과: "<< a.x << "\n";
	++a;
	cout << "++a 결과: " << a.x << "\n";


}