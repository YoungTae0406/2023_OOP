#include <iostream>

using namespace std;
class Animal {
public:

	virtual void speak() {
		std::cout << "�����Ҹ�" << "\n";
	}
	
};

class Dog : public Animal{
public:
	void speak() {
		std::cout << "�۸�" << "\n";
	}
	

};

class Cat : public Animal {

public:

	void speak() {
		std::cout << "�߿�" << "\n";
	}


};

int main() {
	Animal a;
	Dog d;
	Cat c;

	a.speak();
	d.speak();
	c.speak();

	Animal* arr[3];
	arr[0] = new Animal();
	arr[1] = new Dog();
	arr[2] = new Cat();

	for (int i = 0; i < 3; i++) {
		arr[i]->speak();
	}
	for (int i = 0; i < 3; i++) {
		delete arr[i];
	}
	

	return 0;
}