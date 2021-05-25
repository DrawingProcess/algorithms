#include <iostream>
using namespace std;
int memo[30][30] = { 0, };
int nCr(int n, int k) {
	if (n == 0 || n == 1) return 1;
	if (k == 0 || k == n) return 1;
	if (memo[n][k]) return memo[n][k];
	int ans = nCr(n - 1, k - 1) + nCr(n - 1, k);
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	int ret = nCr(n, k);
	cout << ret;
}