#include <iostream>
using namespace std;

int main() {
	int A, B, price;
	cin >> A >> B >> price;
	if (price - B <= 0) cout << -1 << endl;
	else cout << A / (price - B) + 1 << endl;
}