#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	if (1 <= num && num <= 100000) {
		for (int i = num; i > 0; i--)
			cout << i << '\n';
	}
}