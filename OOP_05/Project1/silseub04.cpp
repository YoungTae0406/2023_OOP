#include <iostream>
#include <string>
class Animal {
private:
	std::string name;
public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	Animal& operator+(const Animal& a) {
		name += a.name;
		return *this;
	}

};

int main() {
	Animal cat("Nabi");
	cat.showName();

	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName();

	getchar();
	return 0;
}














// dog가 앞에 있어서 원래 객체가 되고 거기에 cat을 더하는 거라 
// 변경된 원래 객체를 *this로 리턴하고 있기 때문에