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
		//j인덱스가 끝에 도달했으면 i만 움직입니다.
		if (j >= n - 1) {
			sum -= arr[i++];
			if (sum == k) ++cnt;
			continue;
		}
		//sum이 k보다 작으면 j를 움직입니다.
		if (sum < k) {
			sum += arr[++j];
		}
		//sum이 k보다 크면 i를 움직입니다.
		if (sum > k) {
			sum -= arr[i++];
		}
		//sum이 k랑 같으면 cnt를 세고 j를 움직입니다.
		if (sum == k) {
			++cnt;
			sum += arr[++j];
		}
	}
	cout << cnt;
}