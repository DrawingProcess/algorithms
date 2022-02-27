#include <iostream>
using namespace std;

int d[1000001];

long long int dp(int d[], int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x == 2) return 7;
	if (d[x] != 0) return d[x];
	int result = 3 * dp(d, x - 2) + 2 * dp(d, x - 1);
	for (int i = 3; i <= x; i++)
		result += (2 * dp(d, x - i)) % 100000007;
	return d[x] = result % 100000007;
}

long long int d2[1000001][2];
long long int dp2(int x) {
	d2[0][0] = 0;
	d2[1][0] = 2;
	d2[2][0] = 7;
	d2[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		d2[i][1] = (d2[i - 1][1] + d2[i - 3][0]) % 1000000007;
		d2[i][0] = (3 * d2[i - 2][0] + 2 * d2[i - 1][0] + 2 * d2[i][1]) % 1000000007;
	}
	return d2[x][0];
}
int main() {
	int x;
	cin >> x;
	// cout << dp(d, x);
	cout << dp2(x);
}