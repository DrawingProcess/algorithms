#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}

int main() {
	int n, k;
	cin >> n >> k;

	int blank = n - k; // ºóÀÚ¸®¼ö

	cout << factorial(blank + 1) / (factorial(k) * factorial(blank + 1 - k));

	return 0;
}