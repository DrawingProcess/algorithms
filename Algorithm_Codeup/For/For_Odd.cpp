#include <iostream>
using namespace std;
int main() {
	int num, sum = 0;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) sum += num;
	}
	if (sum == 0) sum = -1;
	cout << sum;
}