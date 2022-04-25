#include <iostream>
using namespace std;

int main() {
	int min, max, sum = 0;
	cin >> min >> max;
	int prime_min = max;
	if (min == 1) {
		min++;
	}
	for (int j = min; j <= max; j++) {
		bool prime = true;
		for (int k = 2; k < j; k++) {
			if (j % k == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			prime_min = j > prime_min ? prime_min : j;
			sum += j;
		}
	}
	if (sum == 0) {
		cout << -1 << endl;
	}
	else {
		cout << sum << endl;
		cout << prime_min << endl;
	}
}