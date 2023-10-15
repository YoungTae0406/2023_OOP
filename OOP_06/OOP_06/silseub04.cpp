#include <iostream>
#include <string>

class Person { // ��� Ŭ����
private: 
	std::string name; // �̸�
	int age; // ����
	std::string address; // �ּ�
public:
	Person(std::string n, int a, std::string addr) : name(n), age(a), address(addr) {}
	// setter�� ���� ���ϰ� �Ͽ� �����ڷ� �ʱ�ȭ�������.

	std::string getName() { // name�� getter
		return name;
	}
	int getAge() { // age�� getter
		return age;
	}
	std::string getAddress() { // address�� getter
		return address;
	}
};
using namespace std;
class Student : public Person { // Student�� Person�� ��ӹ���
private:
	string studentID; // �й�
	
public:
	Student(string n, int a, string addr, string id) : Person(n, a, addr), studentID(id) {}
	// Student �����ڷ� Person �����ڸ� �����԰� ���ÿ� ������ �ʱ�ȭ
	string getStudentId() { // �й��� getter
		return studentID;
	}
	void output() { // ����ϴ� �Լ�
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