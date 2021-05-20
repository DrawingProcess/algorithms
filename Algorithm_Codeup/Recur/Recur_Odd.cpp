#include <iostream>
using namespace std;
void print(int a, int b) {
	if (a % 2 == 1) cout << a << " ";
	if (a == b) return;
	print(a + 1, b);
}
int main() {
	int a, b;
	cin >> a >> b;
	print(a, b);
}