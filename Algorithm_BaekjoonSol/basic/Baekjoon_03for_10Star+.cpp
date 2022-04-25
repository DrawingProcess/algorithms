#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	if (1 <= num && num <= 100) {
		for (int i = 1; i <= num; i++) {
			for (int j = num; j > i; j--)
				cout << ' ';
			for (int j = 1; j <= i; j++)
				cout << '*';
			cout << '\n';
		}
	}
}