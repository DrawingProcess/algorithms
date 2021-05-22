#include <iostream>
using namespace std;
int main() {
	int n, k, num;
	cin >> n >> k;
	int result = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num >= k) {
			result = i + 1;
			break;
		}
	}
	cout << result;
}