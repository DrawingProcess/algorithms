#include <iostream>
using namespace std;
int main() {
	int n, k, arr[100000] = {0,};
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int j = 0, sum = arr[0], cnt = 0;
	for (int i = 0; i < n;) {
		//j�ε����� ���� ���������� i�� �����Դϴ�.
		if (j >= n - 1) {
			sum -= arr[i++];
			if (sum == k) ++cnt;
			continue;
		}
		//sum�� k���� ������ j�� �����Դϴ�.
		if (sum < k) {
			sum += arr[++j];
		}
		//sum�� k���� ũ�� i�� �����Դϴ�.
		if (sum > k) {
			sum -= arr[i++];
		}
		//sum�� k�� ������ cnt�� ���� j�� �����Դϴ�.
		if (sum == k) {
			++cnt;
			sum += arr[++j];
		}
	}
	cout << cnt;
}