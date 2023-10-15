#include <iostream>

using namespace std;
class Employee { // 기반 클래스
private:
	string emp_id; // employee id
	string name; // 이름
	int age; // 나이
	string address; // 주소
	float salary; // 봉급

public:
	Employee(string emp, string n, int a, string addr, float sal) :
		emp_id(emp), name(n), age(a), address(addr), salary(sal) {} // Employee 생성자
	string get_emp_id() {return emp_id;} // 직원 id getter
	string get_name() { return name; } // 이름 getter
	int get_age() { return age; } // 나이 getter
	string get_address() { return address; } // 주소 getter
	float get_salary() { return salary; } // 봉급 getter

};

class Manager : public Employee { // Employee를 상속받음
private:
	int team_size; // 팀원 수

public:
	Manager(string emp, string n, int a, string addr, float sal, int ts) :
		Employee(emp, n, a, addr, sal), team_size(ts) {}
	// Manager의 생성자를 생성하고 Employee의 생성자도 생성해 변수를 초기화시킴
	int get_team_size() { return team_size; } // 팀원 수 getter

};

void main() {
	string manager_name;
	cout << "Manager의 이름을 입력해주세요" << endl; // 사용자로부터 입력을 받음
	// 우린 매니저의 이름을 모르기 때문에
	cin >> manager_name;
	Manager manager("EMP001", manager_name, 35, "seoul", 5000.00, 10);

	cout << "Manager Information" << endl;
	cout << "\tEmployee ID : " << manager.get_emp_id() << endl;
	cout << "\tName : " << manager.get_name() << endl;
	cout << "\tAge : " << manager.get_age() << endl;
	cout << "\tAddress : " << manager.get_address() << endl;
	cout << "\tSalary : " << manager.get_salary() << endl;
	cout << "Team Size : " << manager.get_team_size() << endl;

}