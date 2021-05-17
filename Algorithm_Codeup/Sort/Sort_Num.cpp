#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	vector<int> nums;
	int num, a;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end(), cmp);
	for (int i = 0; i < num; i++) {
		cout << nums[i] << " ";
	}
}