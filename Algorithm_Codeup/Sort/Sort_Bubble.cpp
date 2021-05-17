#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> nums, temp;
	int num, a, tmp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		nums.push_back(a);
	}
	temp = nums;
	sort(temp.begin(), temp.end()); // temp: 정렬된 배열, nums: bubblesort로 정렬 예정

	bool flag = true;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
		for (int j = 0; j < num; j++) {
			if (nums[j] != temp[j]) flag = false;
		}
		if (flag) {
			cout << i + 1;
			break;
		}
		flag = true;
	}
}