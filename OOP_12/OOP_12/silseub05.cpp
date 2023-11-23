#include <iostream>
using namespace std;

template <typename T>
void fun(const T& x) {
	static int count = 0;
	cout << "x = " << x << " count = " << count << endl;
	++count;
	return;
}

int main()
{
	fun<int>(1);
	cout << endl;
	fun<int>(1);
	cout << endl;
	fun<double>(1.1);
	cout << endl;
	return 0;
}

//fun<int> 에 해당하는 count는 fun<int>가 호출될때만 count가 증가하고
//fun<double>에 해당하는 count는 fun<double>이 호출될때만 count가 증가함.
// 이 결과를 보니 각 템플릿 인스턴스마다 별도의 static 변수가 생기는 듯 하다.
