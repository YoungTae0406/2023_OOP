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
// ����Ʈ �����ڴ� � �����ڵ� ���ǵ��� �ʾƾ߸� �ڵ����� �����
// ���� int Ÿ���� �Ű������� �޴� �����ڰ� �ϳ� ���ǵ��־
// ����Ʈ �����ڰ� �ڵ����� ������ �ʾ� ������ ������ ����.