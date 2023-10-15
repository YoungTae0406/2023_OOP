class Animal {
public:
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}

private:
	int numberOfLeg;
};

int main() {
	Animal a;

	return 0;
}
// 디폴트 생성자는 어떤 생성자도 정의되지 않아야만 자동으로 생긴다
// 위엔 int 타입의 매개변수를 받는 생성자가 하나 정의돼있어서
// 디폴트 생성자가 자동으로 생기지 않아 컴파일 오류가 떴다.