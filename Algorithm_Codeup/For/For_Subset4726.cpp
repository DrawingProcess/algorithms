#include <iostream>
using namespace std;
int main() {
	int num, con;
	cin >> num >> con;
	int* sum = new int[num];
	int* arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		sum[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		for (int j = i; j < con + i; j++) {
			sum[i] += arr[j];
		}
		if (con + i == num) {
			break;
		}
	}
	int max = sum[0];
	for (int i = 0; i < num - 1; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
		if (con + i == num) {
			break;
		}
	}
	cout << max;
	delete[] sum;
	delete[] arr;
}