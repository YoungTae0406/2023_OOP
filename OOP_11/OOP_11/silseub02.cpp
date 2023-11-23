#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Rect {
	int w, h;
public:
	Rect() : w(0), h(0) {}
	Rect(int w, int h) : w(w), h(h) { }
	int area() const { return w * h; }
	void print() {
		cout << "(" << w << "," << h << "," << area() << ")" << endl;
	}
};
bool compareRect(const Rect& a, const Rect& b) {
	return a.area() < b.area();
}

int main() {
	int numRec = 0;

	cout << "사각형의 개수: ";
	cin >> numRec;

	vector<Rect> rect;

	int a = 0;
	int b = 0;
	for (int i = 0; i < numRec; i++) {
		cout << "사각형의 폭: ";
		cin >> a;
		cout << "사각형의 높이: ";
		cin >> b;
		Rect temp(a, b);
		rect.push_back(temp);
	}
	sort(rect.begin(), rect.end(), compareRect);

	for (int i = 0; i < numRec; i++) {
		rect[i].print();
	}

	return 0;
}
