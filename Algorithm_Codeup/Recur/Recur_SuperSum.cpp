#include <iostream>
using namespace std;
int nums[15][15];
int supersum(int k, int n) {
	if (k == 0) return n;
	if (nums[k][n]) return nums[k][n];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += supersum(k - 1, i);
	}
	nums[k][n] = sum;
	return sum;
}
int main() {
	int k, n;
	while (!cin.eof() && cin >> k >> n) {
		cout << supersum(k, n) << "\n";
	}
	//while ((scanf("%d %d", &k, &n)) != EOF) {
	//	printf("%d\n", supersum(k, n));
	//}
}