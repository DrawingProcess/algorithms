#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> nums, temp;
	int num, a;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		nums.push_back(a);
	}
	temp = nums;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < num; i++) {
		cout << (find(nums.begin(), nums.end(), temp[i]) - nums.begin()) << " ";
	}
}