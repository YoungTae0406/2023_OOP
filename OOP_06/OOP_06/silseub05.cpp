#include <iostream>

using namespace std;
class Employee { // ��� Ŭ����
private:
	string emp_id; // employee id
	string name; // �̸�
	int age; // ����
	string address; // �ּ�
	float salary; // ����

public:
	Employee(string emp, string n, int a, string addr, float sal) :
		emp_id(emp), name(n), age(a), address(addr), salary(sal) {} // Employee ������
	string get_emp_id() {return emp_id;} // ���� id getter
	string get_name() { return name; } // �̸� getter
	int get_age() { return age; } // ���� getter
	string get_address() { return address; } // �ּ� getter
	float get_salary() { return salary; } // ���� getter

};

class Manager : public Employee { // Employee�� ��ӹ���
private:
	int team_size; // ���� ��

public:
	Manager(string emp, string n, int a, string addr, float sal, int ts) :
		Employee(emp, n, a, addr, sal), team_size(ts) {}
	// Manager�� �����ڸ� �����ϰ� Employee�� �����ڵ� ������ ������ �ʱ�ȭ��Ŵ
	int get_team_size() { return team_size; } // ���� �� getter

};

void main() {
	string manager_name;
	cout << "Manager�� �̸��� �Է����ּ���" << endl; // ����ڷκ��� �Է��� ����
	// �츰 �Ŵ����� �̸��� �𸣱� ������
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