#include <iostream>
using namespace std;
int main() {
	int count = 0, n = 5;
	for (int i = 0; i < n; i++) {
		for (int y = 0; y < n; y++) {
			cout << count << " ";
			count++;
		}
		cout << count << "\n";
	}
}