#include <iostream>
using namespace std;
int main() {
	int nums[100001] = { 0, };
	int num, a, max_ = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		nums[a]++;
		if (max_ < a) max_ = a;
	}
	for (int i = 0; i <= max_; i++) 
		for (int j = 0; j < nums[i]; j++)
			cout << i << " ";
}