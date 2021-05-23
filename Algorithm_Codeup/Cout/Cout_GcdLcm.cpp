#include <iostream>
using namespace std;
int Gcd(int a, int b) {
	if (b == 0) return a;
	return Gcd(b, a % b);
}
int Lcm(int a, int b) {
	return a * b / Gcd(a, b);
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << Gcd(a, b) << "\n" << Lcm(a, b);
}