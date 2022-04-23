#include <iostream>
using namespace std;

int main() {
	int iter, num, term = 0;
	cin >> iter;
	for (int i = 0; i < iter; i++) {
		bool prime = true;
		cin >> num;
		if (num == 1) {
			prime = false;
		}
		for (int j = 2; j < num; j++) {
			if (num % j == 0) {
				prime = false;
			}
		}
		if (prime) term++;
	}
	cout << term;
}