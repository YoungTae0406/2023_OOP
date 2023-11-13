#include <iostream>
using namespace std;

class DrawAPI { 
public:
	virtual void drawCircle(int radius, int x, int y) = 0; //순수가상함수 drawCircle
	virtual ~DrawAPI() {} // 메모리누수가 일어나지 않도록 virtual을 사용
};

class RedCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[color:red, radius: " << radius << "] " << "x: " << x << ", " << y << "]\n";
	}
	// 상속받아서 오버라이딩을 함
};

class GreenCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[color:green, radius: " << radius << "] " << "x: " << x << ", " << y << "]\n";
	}
	// 상속받아서 오버라이딩을 함
};

class Shape {
protected:
	DrawAPI* drawAPI; // 추상화 클래스에 구현할 수 있는 클래스를 안에 넣어둠
	Shape(DrawAPI* drawAPI) : drawAPI(drawAPI) {} // 생성자로 초기화
public:
	virtual void draw() = 0; // 순수가상함수
	virtual ~Shape() {}
};

class Circle : public Shape {
private:
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : // x, y, radius, drawAPI를 초기화
		x(x), y(y), radius(radius), Shape(drawAPI) {}
	void draw() override{
		drawAPI->drawCircle(radius, x, y); // drawAPI를 활용해 원을 그림
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); // 업캐스팅으로 redCircle 생성
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); // 업캐스팅으로 greenCircle 생성

	redCircle->draw();
	greenCircle->draw();

	delete redCircle; // 메모리 누수 관리
	delete greenCircle;

	return 0;
}