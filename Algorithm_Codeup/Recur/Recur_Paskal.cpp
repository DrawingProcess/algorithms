#include <iostream>
using namespace std;
int pas[51][51];
int paskal(int r, int c) {
	if (c == 1 || r == 1) {
		return 1;
	}
	else if (c < 1 || r < 1) {
		return 0;
	}
	else if (pas[r][c]) {
		return pas[r][c];
	}
	else {
		pas[r][c] = paskal(r, c - 1) + paskal(r - 1, c);
		return pas[r][c] % 100000000;
	}
}
int main() {
	int r, c;
	cin >> r >> c;
	cout << paskal(r, c);
}