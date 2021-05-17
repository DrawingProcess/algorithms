#include <iostream>
using namespace std;
int main() {
	int r, g, b, cnt = 0;
	cin >> r >> g >> b;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < g; j++) {
			for (int k = 0; k < b; k++) {
				cout << i << " " << j << " " << k << "\n";
				cnt++;
			}
		}
	}
	cout << cnt;
}