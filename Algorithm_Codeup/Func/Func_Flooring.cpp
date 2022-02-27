#include <iostream>
using namespace std;

long long int f(double x) {
	long long int t = (long long int)x;
	if (x < 0)
		return t - 1;
	else
		return t;
}
int main() {
	double x;
	cin >> x;
	cout << f(x);
}