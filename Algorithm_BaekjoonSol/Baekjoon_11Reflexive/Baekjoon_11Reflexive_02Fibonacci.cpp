#include <iostream>
using namespace std;
int Fibonacci(int n) {
	int result = n;
	if (n >= 2)
		result = Fibonacci(n - 1) + Fibonacci(n - 2);
	return result;
}
int main() {
	int N;
	cin >> N;
	cout << Fibonacci(N);
}