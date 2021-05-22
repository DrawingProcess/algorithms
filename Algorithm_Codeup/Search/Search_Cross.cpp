#include <iostream>
using namespace std;
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int a, b, c, d, tmp;
	cin >> a >> b >> c >> d;
	if (a > b) {
		swap(a, b);
	}
	if (c > d) {
		swap(c, d);
	}
	if (a < c && c < b && b < d) cout << "cross";
	else if (a < d && d < b && a > c) cout << "cross";
	else cout << "not cross";
}