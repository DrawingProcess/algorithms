#include <iostream>
using namespace std;

int main() {
	long long N, cnt = 1, range = 0;
	cin >> N;

	while (1) {
		if (N <= range) break;
		range += cnt;
		cnt++;
	}
	if (cnt % 2 == 0) cout << range - N + 1 << "/" << cnt - (range - N + 1);
	else cout << cnt - (range - N + 1) << "/" << range - N + 1;
}