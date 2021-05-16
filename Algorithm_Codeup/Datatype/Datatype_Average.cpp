#include <iostream>
using namespace std;
int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	cout << fixed;
	cout.precision(1);
	int sum = n1 + n2 + n3;
	cout << sum  << "\n" << sum / (double)3;
}