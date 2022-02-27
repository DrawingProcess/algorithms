#include <iostream>
using namespace std;
int digit(int n) {
	int sum = 0;
	while (true) {
		if (n == 0 && sum / 10 == 0) break;
		else if (n == 0 && sum / 10 != 0) {
			n = sum;
			sum = 0;
		}
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	cout << digit(n);
}