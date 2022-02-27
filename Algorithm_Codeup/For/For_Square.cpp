#include <iostream>
using namespace std;
int main() {
	int m, n, nums[10000] = { 0, };
	cin >> m >> n;
	for (int i = 1; i * i <= n; i++) {
		nums[i * i]++;
	}
	int min = n, sum = 0;
	for (int i = m; i <= n; i++) {
		if (nums[i]) {
			sum += i;
			min = min < i ? min : i;
		}
	}
	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << "\n" << min;
	}
}