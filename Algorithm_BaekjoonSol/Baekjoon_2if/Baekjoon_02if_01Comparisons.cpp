#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if ((-10000 <= A && A <= 10000) && (-10000 <= B && B <= 10000)) {
		if (A > B)
			cout << '>';
		else if (A < B)
			cout << '<';
		else if (A = B)
			cout << "==";
	}
}