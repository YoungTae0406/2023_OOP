#include <iostream>
using namespace std;

class Shape { // abstract product
// 만들 객체들의 인터페이스
public:
	virtual void draw() = 0; // 순수가상함수. 꼭 작성해야함
	virtual ~Shape() {}
};

class RoundedRectangle : public Shape { // concrete product 1
// 실제로 만들어질 객체
public:
	void draw() override { // 기반클래스인 Shape의 draw를 오버라이딩함.
		cout << "Inside RoundedRectangle::draw() method.\n";

	}
};
class RoundedSquare : public Shape { // concrete product 2
public:
	void draw() override { // 기반클래스인 Shape의 draw를 오버라이딩함.
		cout << "Inside RoundedSquare::draw() method.\n";

	}
};
class Rectangle : public Shape { // concrete product 3
public:
	void draw() override { // 기반클래스인 Shape의 draw를 오버라이딩함.
		cout << "Inside Rectangle::draw() method.\n";
	}
};
class Square : public Shape { // concrete product 4
public:
	void draw() override { // 기반클래스인 Shape의 draw를 오버라이딩함.
		cout << "Inside Square::draw() method.\n";
	}
};

class AbstractFactory { // 객체 생성에 대한 인터페이스
public:
	virtual Shape* getShape(string shapType) = 0; // 순수가상함수
	

}; // step 3

class ShapeFactory : public AbstractFactory { // concrete factory
// concrete product를 생성한다.
public:
	Shape* getShape(string shapeType) { // Shape인 Renctangle과 Square를 만든다.
		// 반환타입이 Shape* 이고 생성은 그 파생클래스이므로 업캐스팅이 사용된다.
		if (shapeType == "RECTANGLE") {
			return new Rectangle();
		}
		else if (shapeType == "SQUARE") {
			return new Square();
		}
	}
};
class RoundedShapeFactory : public AbstractFactory {
public:
	Shape* getShape(string shapeType) { //RoundedRectangle과 RoundedSquare를만든다.
		// 반환타입이 Shape* 이고 생성은 그 파생클래스이므로 업캐스팅이 사용된다.
		if (shapeType == "RECTANGLE") {
			return new RoundedRectangle();
		}
		else if (shapeType == "SQUARE") {
			return new RoundedSquare();
		}
	}
};

class FactoryProducer { // factory를 만든다.
public:
	 static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
	// 업캐스팅함. rounded가 false.

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); // Rectangle 객체가 생성됨
	// 업캐스팅 개념이 쓰임.
	shape1->draw(); // Rectangle의 draw함수가 호출

	Shape* shape2 = shapeFactory->getShape("SQUARE"); // Square 객체가 생성됨
	shape2->draw(); // Square의 draw 함수가 호출

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
	// 업캐스팅. Rounded 팩토리가 만들어짐.

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); // RoundedRectangle 객체가 생성
	shape3->draw();// RoundedRectangle의 draw 함수가 호출

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); // RoundedSquare 객체가 생성
	shape4->draw(); // RoundedSquare의 draw 함수가 호출.

	// 메모리 해제
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;
	delete shapeFactory;
	delete shapeFactory1;

	return 0;
}