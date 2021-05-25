#include <iostream>
using namespace std;
int Gcd(int a, int b) {
	if (b == 0) return a;
	return Gcd(b, a % b);
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << Gcd(Gcd(a, b), c);
}