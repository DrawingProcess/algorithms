#include <iostream>
using namespace std;

int main() {
	int paper[101][101] = { 0, };
	int n, L, B;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> L >> B;
		for (int j = B; j < B + 10; j++) {
			for (int k = L; k < L + 10; k++) {
				paper[j][k]++;
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j <= 100; j++) {
		for (int k = 0; k <= 100; k++) {
			if (paper[j][k] >= 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
}