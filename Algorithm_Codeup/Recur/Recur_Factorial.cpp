#include <iostream>
using namespace std;
int sum(int num) {
	int s = num;
	if (num == 1) return num;
	return s * sum(num - 1);
}
int main() {
	int n;
	cin >> n;
	cout << sum(n);
}