#include <iostream>
using namespace std;

int main() {
	int A, B, C, line1, line2, line3, line4;
	cin >> A >> B>> C;
	line1 = ((A + B) % C);
	line2 = ((A % C) + (B % C)) % C;
	line3 = (A*B) % C;
	line4 = ((A % C) * (B % C)) % C;
	cout << line1 << endl;
	cout << line2 << endl;
	cout << line3 << endl;
	cout << line4 << endl;
}