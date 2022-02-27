#include <iostream>
using namespace std;
int main() {
	int num, max_i, max = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		if (max < num) {
			max = num;
			max_i = i + 1;
		}
	}
	cout << max << "\n" << max_i;
}