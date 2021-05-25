#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <string>
using namespace std;

int cnt = 0;
void f(int n, int bit) {
    if (!n) {
        cnt++;
        return;
    }
    f(n - 1, 1);
    if (bit) f(n - 1, 0);
}
int main() {
	vector<int> nums;
	vector<string> bit;
	int target, m, num;
	cin >> target >> m;
	const int n = m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}
	for (int i = 0; i < pow(2, n); i++) {
		bit.push_back(bitset<20>(i).to_string().substr(20-n));
	}
	int sum, cnt = 0;
	for (int i = 0; i < pow(2, n); i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (bit[i][j] == '0' && nums[j] > 0) {
				nums[j] = -nums[j];
			}
			else if (bit[i][j] == '1' && nums[j] < 0) {
				nums[j] = -nums[j];
			}
			sum += nums[j];
		}
		if (sum == target) cnt++;
	}
	cout << cnt;
}