#include <iostream>
using namespace std;

int main() {
	long long h, b, c, s;
	cin >> h >> b >> c >> s;
	double result = h * b * s * c;
	result /= (8 * 1024 * 1024);
	cout << fixed;
	cout.precision(1);
	cout << result << " MB";
}