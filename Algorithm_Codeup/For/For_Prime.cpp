#include <iostream>
using namespace std;
bool isPrime(int num) {
	int i = 2;
	if (num == 0 || num == 1) return false;
	while (i * i <= num) {
		if (num % i == 0) return false;
		i++;
	}
	return true;
}
int main() {
	int m, n;
	cin >> m >> n;
	int min = n, sum = 0;
	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			sum += i;
			min = min < i ? min : i;
		}
	}
	cout << sum << "\n" << min;
}