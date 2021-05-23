#include <iostream>
#include <string>
using namespace std;
int main() {
	string nums;
	cin >> nums;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[nums.size() - i - 1];
	}
}