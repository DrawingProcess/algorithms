# include <iostream>
using namespace std;

int bino(int n, int r) {
	if (r == 0 || n == r) return 1;
	return bino(n - 1, r - 1) + bino(n - 1, r);
}

// memoization
int cache[30][30] = {-1,};
int bino2(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1) return cache[n][r];
	return bino2(n - 1, r - 1) + bino2(n - 1, r);
}

int main() {
	memset(cache, -1, sizeof(cache));
	cout << bino2(30, 30) << endl;
}