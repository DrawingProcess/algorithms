#include <iostream>
using namespace std;

int main() {
	const int n = 10;
	int length[n];
	int arr[n] = { 6, 2, 5, 1, 7, 4, 8, 3, 5, 9 };
	for (int i = 0; i < n; i++) {
		length[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				length[i] = max(length[i], length[j] + 1);
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << length[i] << "\t";
	cout << "\n";
}