#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> hex >> num;
	for (int i = 1; i <= 15; i++) {
		cout << hex << uppercase << num << '*' << i << '=' << i * num << "\n";
	}
}