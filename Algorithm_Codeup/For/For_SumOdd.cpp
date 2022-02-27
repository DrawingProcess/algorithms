#include <iostream>
using namespace std;
int main() {
	int num, sum = 0, min = 100;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) {
			sum += num;
			if (min > num) min = num;
		}
	}
	if (sum == 0) {
		cout << -1; 
		return 0;
	}
	else {
		cout << sum << "\n" << min;
	}
}