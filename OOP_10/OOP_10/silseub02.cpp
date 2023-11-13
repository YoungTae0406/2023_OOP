#include <iostream>
using namespace std;

class DrawAPI { 
public:
	virtual void drawCircle(int radius, int x, int y) = 0; //���������Լ� drawCircle
	virtual ~DrawAPI() {} // �޸𸮴����� �Ͼ�� �ʵ��� virtual�� ���
};

class RedCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[color:red, radius: " << radius << "] " << "x: " << x << ", " << y << "]\n";
	}
	// ��ӹ޾Ƽ� �������̵��� ��
};

class GreenCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[color:green, radius: " << radius << "] " << "x: " << x << ", " << y << "]\n";
	}
	// ��ӹ޾Ƽ� �������̵��� ��
};

class Shape {
protected:
	DrawAPI* drawAPI; // �߻�ȭ Ŭ������ ������ �� �ִ� Ŭ������ �ȿ� �־��
	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // �����ڷ� �ʱ�ȭ
public:
	virtual void draw() = 0; // ���������Լ�
	virtual ~Shape() {}
};

class Circle : public Shape {
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : // x, y, radius, drawAPI�� �ʱ�ȭ
		x(x), y(y), radius(radius), Shape(drawAPI) {}
	void draw() override{
		drawAPI->drawCircle(radius, x, y); // drawAPI�� Ȱ���� ���� �׸�
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); // ��ĳ�������� redCircle ����
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); // ��ĳ�������� greenCircle ����

	redCircle->draw();
	greenCircle->draw();

	delete redCircle; // �޸� ���� ����
	delete greenCircle;

	return 0;
}