#include <iostream>
using namespace std;

int main() {
	int x1, x2, x3;
	while (1) {
		cin >> x1 >> x2 >> x3;
		if (x1 == 0 && x2 == 0 && x3 == 0)
			break;
		if (x2 > x1) {
			if (x3 > x2) {
				if (x1 * x1 + x2 * x2 == x3 * x3) {
					cout << "right\n";
				}
				else
					cout << "wrong\n";
			}
			else if (x2 > x3) {
				if (x1 * x1 + x3 * x3 == x2 * x2) {
					cout << "right\n";
				}
				else
					cout << "wrong\n";
			}
			else
				cout << "wrong\n";
		}
		else {
			if (x3 * x3 + x2 * x2 == x1 * x1) {
				cout << "right\n";
			}
			else
				cout << "wrong\n";
		}
	}
}