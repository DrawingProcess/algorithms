#include <iostream>
#include <cmath>
using namespace std;

// Sieve of Eratosthenes
int main() {
	int num;
	while (1) {
		int count = 0;
		cin >> num;
		if (num == 0) break;
		bool* prime = new bool[2 * num + 1];
		fill_n(prime, 2 * num + 1, 1); // prime array initialization
		prime[0] = false;
		prime[1] = false;

		for (int i = 2; i <= sqrt(2 * num); i++)
			if (prime[i] == true)
				for (int j = i * 2; j <= 2 * num; j += i)
					prime[j] = false;
		for (int i = num + 1; i <= 2 * num; i++)
			if (prime[i] == true)
				count++;

		cout << count << '\n';
	}
}