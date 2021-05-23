#include <iostream>
using namespace std;
int tax(int num) {
	if (num <= 500) {
		return num * 70 / 100;
	}
	else if (num <= 1500) {
		return 350 + (num - 500) * 40 / 100;
	}
	else if (num <= 4500) {
		return 750 + (num - 1500) * 15 / 100;
	}
	else if (num <= 10000) {
		return 1200 + (num - 4500) * 5 / 100;
	}
	else {
		return 1475 + (num - 10000) * 2 / 100;
	}
}
int main() {
	int num;
	cin >> num;
	cout << tax(num);
}