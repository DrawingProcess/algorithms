#include <iostream>
using namespace std;
int n;
long long int d[110];
long long f() {
	long long min_i, min = 987654321;
	for (int i = 1; i <= n; i++) {
		if (min > d[i]) {
			min = d[i];
			min_i = i + 1;
		}
	}
	return min;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	cout << f();
}