#include <iostream>
using namespace std;

int main() {
	int a, b, Mul1, Mul2, Mul3, MulTotal;
	cin >> a >> b;
	Mul1 = a * (b % 10);
	Mul2 = a * (b % 100 - b % 10) / 10;
	Mul3 = a * (b % 1000 - b % 100) / 100;
	MulTotal = Mul1 + 10 * Mul2 + 100 * Mul3;
	cout << Mul1 << endl
		<< Mul2 << endl
		<< Mul3 << endl
		<< MulTotal << endl;
}