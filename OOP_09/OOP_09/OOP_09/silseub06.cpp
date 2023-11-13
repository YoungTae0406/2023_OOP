#include <iostream>
#include <vector>

class Shape {
public:
	virtual void Draw() {
		std::cout << "Shape Draw" << std::endl;
	}
};

// �簢��
class Rect : public Shape {
public:
	void Draw() {
		std::cout << "Rect Draw\n";
	}
	// write code
};

// ��
class Circle : public Shape {
public:
	void Draw() {
		std::cout << "Circle Draw\n";
	}
	// write code
};

// �ﰢ��
class triangle : public Shape {
public:
	void Draw() {
		std::cout << "triangle Draw\n";
	}
	// write code
};

int main() {
	std::vector<Shape*> v1; // ���� ���� ����
	v1.push_back(new Rect);
	v1.push_back(new Circle);
	v1.push_back(new triangle);
	for (int i = 0; i < v1.size(); i++)
		v1[i]->Draw();
}