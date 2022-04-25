#include <iostream>
#include <cmath>
using namespace std;

// Sieve of Eratosthenes
int main() {
	int min, max;
	cin >> min;
	cin >> max;
	bool* prime = new bool[max + 1];
	fill_n(prime, max + 1, 1); // prime array initialization
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(max); i++)
		if (prime[i] == true)
			for (int j = i * 2; j <= max; j += i)
				prime[j] = false;
	for (int i = min; i <= max; i++)
		if (prime[i] == true)
			cout << i << "\n";
}

// my sol
//int main() {
//	int min, max;
//	cin >> min >> max;
//	if (min == 1) {
//		min++;
//	}
//	for (int j = min; j <= max; j++) {
//		bool prime = true;
//		for (int k = 2; k < j; k++) {
//			if (j % k == 0) {
//				prime = false;
//				break;
//			}
//		}
//		if (prime) cout << j << endl;
//	}
//}