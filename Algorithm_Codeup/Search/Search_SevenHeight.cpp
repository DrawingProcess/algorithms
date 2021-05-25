#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums;
	int num;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int arr[9]{ 0, 0, 1, 1, 1, 1, 1, 1, 1};
	do {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (arr[i]) {
				sum += nums[i];
			}
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (arr[i]) {
					cout << nums[i] << " ";
				}
			}
			break;
		}
	} while (next_permutation(arr, arr + 9));
}