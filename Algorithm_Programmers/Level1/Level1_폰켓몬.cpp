#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> nums) {
	int answer = 0;
	// answer -> sort�� ����ؼ� Ǯ� ��.
	vector<int> ans;
	bool apply;
	for (int i = 0; i < nums.size(); i++) {
		apply = true;
		for (int j = 0; j < ans.size(); j++) {
			if (ans[j] == nums[i]) {
				apply = false;
			}
		}
		if (apply && ans.size() < nums.size() / 2) {
			ans.push_back(nums[i]);
			answer++;
		}
	}
	//
}
int main() {
	vector<int> nums = { 3,1,2,3 };
	cout << solution(nums) << endl;
}