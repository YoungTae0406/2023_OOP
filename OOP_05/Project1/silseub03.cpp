#include <iostream>
#include <string>
class Animal {
private:
	std::string name;
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	cat.showName();

	Animal dog("Jindo");
	dog.showName();

	Animal catDog = dog + cat;

	catDog.showName();
	dog.showName();

	getchar();
	return 0;