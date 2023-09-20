#include <iostream>

int findMax(int (&refa)[5]) {
	int max_temp = -9999;
	int length = sizeof(refa) / sizeof(refa[0]);
	for (int i = 0; i < length; i++) {
		if (refa[i] > max_temp) {
			max_temp = refa[i];
		}
	}
	return max_temp;
}

int main() {
	int array[5] = { 1, 3, 5, 7, 9 };

	int(&refArray)[5] = array;
	std::cout << "The maximum value is: " << findMax(refArray) << std::endl;
	return 0;

}