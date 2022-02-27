#include <iostream>
using namespace std;
int main() {
	int n, a, b;
	cin >> n;
	if (n >= 2013) {
		n = (n - 2013) % 60;
		a = (n + 5) % 12;
		b = (n + 9) % 10;
	}
	else {
		n = (2013 - n) % 60;
		a = 5 - (n % 12);
		b = 9 - (n % 10);
		if (a < 0) a += 12;
		if (b < 0) a += 10;
	}
	cout << char('A'+a) << b;
}