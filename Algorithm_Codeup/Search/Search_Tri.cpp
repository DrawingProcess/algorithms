#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (n - i - j < j) break;
			if (n - i - j < i + j) cnt++;
		}
	}
	cout << cnt;
}