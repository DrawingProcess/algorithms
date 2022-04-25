#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int arr[10] = {0};
	cin >> A >> B >> C;

	int result = A * B * C;
	while (result != 0) {
		arr[result % 10] += 1;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}