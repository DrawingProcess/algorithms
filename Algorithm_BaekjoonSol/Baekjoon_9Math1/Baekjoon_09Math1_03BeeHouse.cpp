#include <iostream>
using namespace std;
int main() {
	int cnt = 1;
	long long N, range = 1, tmp = 1;
	cin >> N;

	while (true) {
		if (range >= N) {
			break;
		}
		tmp = 6 * (cnt++);
		range += tmp;
	}
	cout << cnt;
}