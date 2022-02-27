#include <iostream>
using namespace std;
int main() {
	int num, sum = 0, nums[101] = { 0, };
	for (int i = 0; i < 10; i++) {
		cin >> num;
		sum += num;
		nums[num / 10]++;
	}
	int freq = 0, freq_i;
	for (int i = 0; i <= 100; i++) {
		if (nums[i] > freq) {
			freq = nums[i];
			freq_i = i;
		}
	}
	cout << sum / 10 << "\n" << freq_i * 10;
}