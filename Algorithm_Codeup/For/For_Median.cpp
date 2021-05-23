#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums;
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	cout << nums[nums.size() / 2];
}