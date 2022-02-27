#include <iostream>
using namespace std;
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	//cout << (n1 && n2); // AND
	//cout << (n1 || n2); // OR
	//cout << ((n1 && !n2) || (!n1 && n2)); // XOR
	cout << ((n1 && n2) || (!n1 && !n2)); // XOR
}