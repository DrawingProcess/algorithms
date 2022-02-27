#include <iostream>
using namespace std;
void print(int num, int n) {
	cout << num - n + 1 << "\n";
	if (num == n) return;
	print(num, n + 1);
}
int main() {
	int num;
	cin >> num;
	print(num, 1);
}