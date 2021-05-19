#include <iostream>
using namespace std;
double ABS(double n) {
	if (n < 0) return -n;
	return n;
}
int main() {
	double n;
	cin >> n;
	cout << ABS(n);
}