#include <iostream>
using namespace std;
int Fibo(int* nums, int n) {
	if (n == 1 || n == 2) return 1;
	if (!nums[n]) nums[n] = Fibo(nums, n - 1) + Fibo(nums, n - 2);
	return nums[n] % 10009;
}
int main() {
	int nums[201] = { 0, };
	int n;
	cin >> n;
	cout << Fibo(nums, n);
}