#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
int max_element(vector<int> a) {
	/*vector<int>::iterator iter;
	int temp = -INFINITY;
	for (iter = a.begin(); iter != a.end(); iter++) {
		if (temp < *iter) {
			temp = *iter;
		}

	}*/
	int result = *max_element(a.begin(), a.end());
	return result;



}
int min_element(vector<int> a) {
	int result = *min_element(a.begin(), a.end());
	return result;
}


int main() {
	vector<int> a(10);
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		//cout << a[i] << "\n";
	}
	cout << max_element(a) << "\n";
	cout << min_element(a) << "\n";



	return 0;
}
