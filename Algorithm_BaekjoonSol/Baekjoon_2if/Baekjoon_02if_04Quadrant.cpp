#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if ((-1000 <= x && x <= 1000 && x != 0) && (-1000 <= y && y <= 1000 && y != 0)) {
		if (x > 0 && y > 0)
			cout << '1';
		else if (x < 0 && y > 0)
			cout << '2';
		else if (x < 0 && y < 0)
			cout << '3';
		else if (x > 0 && y < 0)
			cout << '4';
	}
}