#include <iostream>
using namespace std;

int main() {
	int result;
	cin >> result;
	if (0 <= result && result <= 100) {
		if (90 <= result && result <= 100)
			cout << 'A';
		else if (80 <= result && result < 90)
			cout << 'B';
		else if (70 <= result && result < 80)
			cout << 'C';
		else if (60 <= result && result < 70)
			cout << 'D';
		else
			cout << 'F';
	}
}