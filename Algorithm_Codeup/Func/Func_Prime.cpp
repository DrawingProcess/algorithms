#include <iostream>
using namespace std;

void f(int n) {
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			cout << "composite";
			return;
		}
	}
	cout << "prime";
	return;
}
int main() {
	int n;
	cin >> n;
	f(n);
}