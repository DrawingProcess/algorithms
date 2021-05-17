#include <iostream>
using namespace std;

int main() {
	long long w, h, b;
	cin >> w >> h >> b;
	double result = w * h * b;
	result /= (8 * 1024 * 1024);
	cout << fixed;
	cout.precision(2);
	cout << result << " MB";
}