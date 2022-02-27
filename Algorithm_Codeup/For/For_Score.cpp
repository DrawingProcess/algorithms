#include <iostream>
using namespace std;
int main() {
	int n, num, sum = 0, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num) {
			sum += cnt;
			cnt++;
		}
		else {
			cnt = 1;
		}
	}
	cout << sum;
}