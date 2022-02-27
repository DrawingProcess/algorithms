#include <iostream>
using namespace std;

void f(int num) {
	// cout << num << "\n"; // basic
	if (num == 1) {
		return;
	}
	else if (num % 2 == 0) {
		num /= 2;
	}
	else if (num % 2 == 1) {
		num = 3 * num + 1;
	}
	f(num);
	cout << num << "\n"; // reverse;
}
int main() {
	int num;
	cin >> num;
	f(num);
	cout << num << "\n"; // reverse;
}