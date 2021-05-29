#include <iostream>
using namespace std;
int main() {
	int n, num, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int max = 0, nums[6] = { 0, }, result;
		for (int j = 0; j < 4; j++) {
			cin >> num;
			nums[num - 1]++;
		}
		for (int j = 0; j < 6; j++) {
			max = nums[j] > max ? nums[j] : max;
		}
		if (max == 4) {
			for (int j = 0; j < 6; j++)
				if (nums[j] == max)
					result = 50000 + (j + 1) * 5000;
		}
		else if (max == 3) {
			for (int j = 0; j < 6; j++)
				if (nums[j] == max)
					result = 10000 + (j + 1) * 1000;
		}
		else if (max == 2) {
			int sum = 0, cnt = 0;
			for (int j = 0; j < 6; j++) {
				if (nums[j] == max)
					cnt++;
			}
			if (cnt == 2) {
				sum = 2000;
				for (int j = 0; j < 6; j++) {
					if (nums[j] == max)
						sum += (j + 1) * 500;
				}
				result = sum;
			}
			else if (cnt == 1) {
				for (int j = 0; j < 6; j++) {
					if (nums[j] == max)
						result = 1000 + (j + 1) * 100;
				}
			}
		}
		else {
			max = 0;
			for (int j = 0; j < 6; j++) {
				if (nums[j])
					max = j + 1;
			}
			result = max * 100;
		}
		m = result > m ? result : m;
	}
	cout << m;
}