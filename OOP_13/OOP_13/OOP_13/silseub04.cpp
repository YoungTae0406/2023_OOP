#include <iostream>
class Shape {
public:
	void virtual draw() = 0;
	virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
	void draw() override {
		std::cout << "Shape: Rectangle\n";
	}
};
class Circle : public Shape {
public:
	void draw() override {
		std::cout << "Shape: Circle\n";
	}
};

class ShapeDecorator : public Shape {
protected: 
	Shape* decoratedShape;
public:
	ShapeDecorator(Shape* decoratedShape) : decoratedShape(decoratedShape) {}
	void draw() {
		decoratedShape->draw();
	}
};
class RedShapeDecorator : public ShapeDecorator {
private:
	void setRedBorder(Shape* decoratedShape) {
		std::cout << "Border Color: Red\n";
	}

public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}
	void draw() override {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}
};

int main() {
	Shape* circle = new Circle();
	Shape* redcircle = new RedShapeDecorator(new Circle());
	Shape* redRectangle = new RedShapeDecorator(new Rectangle());
	std::cout << "Circle with normal border\n";
	circle->draw();

	std::cout << "Circle of red border\n";
	redcircle->draw();

	std::cout << "Rectangle of red border\n";
	redRectangle->draw();

	return 0;
}