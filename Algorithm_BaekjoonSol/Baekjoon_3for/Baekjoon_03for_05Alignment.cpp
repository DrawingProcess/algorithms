#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	if (1 <= num && num <= 100000) {
		for (int i = 1; i <= num; i++)
			cout << i << '\n';
	}
}