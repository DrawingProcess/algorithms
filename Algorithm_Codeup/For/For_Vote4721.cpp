#include <iostream>
using namespace std;
pair<int, int> nums(pair<int, int> max, pair<int, int> sum, int cnt[4][3], bool& flag) {
	for (int i = 2; i >= 0; i--) {
		if (cnt[max.first][i] > cnt[sum.first][i]) {
			max = make_pair(max.first, max.second);
			flag = true;
			break;
		}
		else if (cnt[max.first][i] < cnt[sum.first][i]) {
			max = make_pair(sum.first, sum.second);
			flag = true;
			break;
		}
		else {
			continue;
		}
	}
	//if (!flag)
	//	max = make_pair(0, max.second);
	return max;
}
int main() {
	int num, a, b, c, cnt[4][3] = { 0, };
	pair<int, int> sumA, sumB, sumC, max;
	max = make_pair(0, 0);
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b >> c;
		sumA = make_pair(1, sumA.second + a);
		sumB = make_pair(2, sumB.second + b);
		sumC = make_pair(3, sumC.second + c);
		cnt[1][a - 1]++;
		cnt[2][b - 1]++;
		cnt[3][c - 1]++;
	}
	max = sumA.second > max.second ? sumA : max;
	max = sumB.second > max.second ? sumB : max;
	max = sumC.second > max.second ? sumC : max;
	bool flag = false, same = false;
	if (max.first != sumA.first && max.second == sumA.second) {
		max = nums(max, sumA, cnt, flag);
		same = true;
	}
	if (max.first != sumB.first && max.second == sumB.second) {
		max = nums(max, sumB, cnt, flag);
		same = true;
	}
	if (max.first != sumC.first && max.second == sumC.second) {
		max = nums(max, sumC, cnt, flag);
		same = true;
	}
	if (flag || (!flag && !same))
		cout << max.first << " " << max.second;
	else
		cout << 0 << " " << max.second;
}