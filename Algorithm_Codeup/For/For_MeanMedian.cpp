#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> nums;
	int num, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	cout << sum / nums.size() << "\n" << nums[nums.size() / 2];
}