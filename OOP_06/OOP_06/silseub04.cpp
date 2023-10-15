#include <iostream>
#include <string>

class Person { // 기반 클래스
private: 
	std::string name; // 이름
	int age; // 나이
	std::string address; // 주소
public:
	Person(std::string n, int a, std::string addr) : name(n), age(a), address(addr) {}
	// setter를 쓰지 못하게 하여 생성자로 초기화해줘야함.

	std::string getName() { // name의 getter
		return name;
	}
	int getAge() { // age의 getter
		return age;
	}
	std::string getAddress() { // address의 getter
		return address;
	}
};
using namespace std;
class Student : public Person { // Student는 Person을 상속받음
private:
	string studentID; // 학번
	
public:
	Student(string n, int a, string addr, string id) : Person(n, a, addr), studentID(id) {}
	// Student 생성자로 Person 생성자를 생성함과 동시에 변수를 초기화
	string getStudentId() { // 학번의 getter
		return studentID;
	}
	void output() { // 출력하는 함수
		std::cout << "Student Information" << std::endl;
		std::cout << "Name : " << getName() << std::endl;
		std::cout << "Age : " << getAge() << std::endl;
		std::cout << "Address : " << getAddress() << std::endl;
		std::cout << "Student ID : " << getStudentId() << std::endl;
	}

};

void main() {
	Student student("kimyeongtae", 10, "daejeon", "201802073");
	student.output();

}