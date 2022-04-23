#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, even, min;
	bool* prime;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> even;
		min = even;
		prime = new bool[even + 1];
		fill_n(prime, even + 1, 1);
		prime[0] = false;
		prime[1] = false;
		for (int j = 2; j <= sqrt(even); j++)
			if (prime[j] == true)
				for (int k = j * 2; k <= even; k += j)
					prime[k] = false;
		for (int j = 0; j <= even; j++)
			if (prime[j] == true && prime[even - j] == true) {
				min = min > abs((even - j) - j) ? abs((even - j) - j) : min;
			}
		cout << (even - min) / 2 << ' ' << even - (even - min) / 2 << '\n';
	}
}