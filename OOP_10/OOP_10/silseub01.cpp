#include <iostream>
using namespace std;

class Shape { // abstract product
// ���� ��ü���� �������̽�
public:
	virtual void draw() = 0; // ���������Լ�. �� �ۼ��ؾ���
	virtual ~Shape() {}
};

class RoundedRectangle : public Shape { // concrete product 1
// ������ ������� ��ü
public:
	void draw() override { // ���Ŭ������ Shape�� draw�� �������̵���.
		cout << "Inside RoundedRectangle::draw() method.\n";

	}
};
class RoundedSquare : public Shape { // concrete product 2
public:
	void draw() override { // ���Ŭ������ Shape�� draw�� �������̵���.
		cout << "Inside RoundedSquare::draw() method.\n";

	}
};
class Rectangle : public Shape { // concrete product 3
public:
	void draw() override { // ���Ŭ������ Shape�� draw�� �������̵���.
		cout << "Inside Rectangle::draw() method.\n";
	}
};
class Square : public Shape { // concrete product 4
public:
	void draw() override { // ���Ŭ������ Shape�� draw�� �������̵���.
		cout << "Inside Square::draw() method.\n";
	}
};

class AbstractFactory { // ��ü ������ ���� �������̽�
public:
	virtual Shape* getShape(string shapType) = 0; // ���������Լ�
	

}; // step 3

class ShapeFactory : public AbstractFactory { // concrete factory
// concrete product�� �����Ѵ�.
public:
	Shape* getShape(string shapeType) { // Shape�� Renctangle�� Square�� �����.
		// ��ȯŸ���� Shape* �̰� ������ �� �Ļ�Ŭ�����̹Ƿ� ��ĳ������ ���ȴ�.
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
	Shape* getShape(string shapeType) { //RoundedRectangle�� RoundedSquare�������.
		// ��ȯŸ���� Shape* �̰� ������ �� �Ļ�Ŭ�����̹Ƿ� ��ĳ������ ���ȴ�.
		if (shapeType == "RECTANGLE") {
			return new RoundedRectangle();
		}
		else if (shapeType == "SQUARE") {
			return new RoundedSquare();
		}
	}
};

class FactoryProducer { // factory�� �����.
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
	// ��ĳ������. rounded�� false.

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); // Rectangle ��ü�� ������
	// ��ĳ���� ������ ����.
	shape1->draw(); // Rectangle�� draw�Լ��� ȣ��

	Shape* shape2 = shapeFactory->getShape("SQUARE"); // Square ��ü�� ������
	shape2->draw(); // Square�� draw �Լ��� ȣ��

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
	// ��ĳ����. Rounded ���丮�� �������.

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); // RoundedRectangle ��ü�� ����
	shape3->draw();// RoundedRectangle�� draw �Լ��� ȣ��

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); // RoundedSquare ��ü�� ����
	shape4->draw(); // RoundedSquare�� draw �Լ��� ȣ��.

	// �޸� ����
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;
	delete shapeFactory;
	delete shapeFactory1;

	return 0;
}