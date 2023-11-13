#include <iostream>

class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};
class Derived : public Base {
public:
	void func_3() {
		func_1();
		func_2();
	}
};
int main() {
	Derived d;
	d.func_3();
	d.func_1();
}

// protected로 상속돼서 Base의 public인 func_1 이 protected로 바뀌었다.
// 그래서 protected를 public으로 바꿈

