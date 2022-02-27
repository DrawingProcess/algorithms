#include <iostream>
using namespace std;
int main() {
	int n, t, min = 24;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		min = min < t ? min : t;
	}
	cout << min;
}