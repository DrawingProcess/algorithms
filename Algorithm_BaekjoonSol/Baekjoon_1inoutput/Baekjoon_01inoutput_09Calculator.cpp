#include <iostream>
using namespace std;

int main() {
	int a, b, sum, sub, mul, div, rest;
	cin >> a >> b;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	div = a / b;
	rest = a % b;
	cout << sum << endl
		<< sub << endl
		<< mul << endl
		<< div << endl
		<< rest << endl;
}