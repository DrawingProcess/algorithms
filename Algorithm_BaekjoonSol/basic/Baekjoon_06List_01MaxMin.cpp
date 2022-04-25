#include <iostream>
using namespace std;

int main() {
	int num, max, min;
	cin >> num;
	if (num >= 1 && num <= 1000000) {
		int* elem = new int[num];
		for (int i = 0; i < num; i++) {
			cin >> elem[i];
			if (i >= 1) {
				max = max >= elem[i] ? max : elem[i];
				min = min <= elem[i] ? min : elem[i];
			}
			else {
				max = elem[i];
				min = elem[i];
			}
		}
		cout << min << ' ' << max;
		delete[] elem;
	}
}