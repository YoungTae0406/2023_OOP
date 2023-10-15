#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>


class Animal {


	char* name;
	int age;
public:
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(const Animal& a) {//Copy constructor with deep copy
		age = a.age;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
		std::cout << "Copy constructor is invoked!!\n";
	}

	Animal(Animal&& a) noexcept {//Move constructor with Shallow copy
		age = a.age;
		name = a.name;
		std::cout << "Move constructor is invoked!!\n";
		a.name = nullptr;
	}
	~Animal() {
		std::cout << "Destructor!!" << std::endl;
		if (name) delete[] name;
	}
	void changeName(const char* newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
			<< age << std::endl;
	}
};


int main() {
	Animal A(10, "Jenny");


	A.printAnimal();


	std::vector<Animal> vec; //Vector for Animal type


	std::cout << "-----1st push-----\n";
	vec.push_back(A);   //Insert an Animal object to vec
	std::cout << "-----2nd push-----\n";
	vec.push_back(A);
	std::cout << "-----3rd push-----\n";
	vec.push_back(A);
	std::cout << "-----4th push-----\n";
	vec.push_back(A);
	std::cout << "-----5th push-----\n";
	vec.push_back(A);


	A.printAnimal();
	vec[0].printAnimal();
	vec[1].printAnimal();
	vec[2].printAnimal();
	vec[3].printAnimal();
	vec[4].printAnimal();


	return 0;
}

// 복사 생성자는 new delete 반복으로 인한 속도 저하가 있을 수 있다.
// 이동 생성자를 같이 사용할 경우 new delete 와 같이 연산을 많이 해야하는 명령을 실행하지 않기 때문에
// 비교적 빠른 속도로 가능하다. 이동 생성자에선 shallow copy로 해도 되기 때문에
// 왜 shallow copy로 되는가? 이동 생성자는 기존의 것을 지우고 이동을 시키는 거기 때문에
