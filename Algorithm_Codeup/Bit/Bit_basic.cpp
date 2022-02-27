#include <iostream>
using namespace std;
int main() {
	int n, n2;
	cin >> n >> n2;
	//cout << ~n; // bitwise not
	//cout << (n & n2); // bitwise and
	//cout << (n | n2); // bitwise or
	cout << (n ^ n2); // bitwise or
}