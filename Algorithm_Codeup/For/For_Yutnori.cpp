#include <iostream>
using namespace std;
int main() {
	int num, cnt = 0;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int i = 0; i < 4; i++) {
			cin >> num;
			if (num)
				cnt++;
		}
		if (cnt == 4) {
			cout << "E\n";
		}
		else if (cnt == 3) {
			cout << "A\n";
		}
		else if (cnt == 2) {
			cout << "B\n";
		}
		else if (cnt == 1) {
			cout << "C\n";
		}
		else if (cnt == 0) {
			cout << "D\n";
		}
	}
}