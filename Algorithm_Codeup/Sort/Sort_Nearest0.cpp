#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return abs(a) < abs(b);
}
int main() {
	vector<int> liquid;
	int num, li;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> li;
		liquid.push_back(li);
	}
	int m = 2000000000, a, b;
	sort(liquid.begin(), liquid.end(), cmp);
	for (int i = 0; i < num - 1; i++)
		if (m > abs(liquid[i] + liquid[i + 1])) {
			m = abs(liquid[i] + liquid[i + 1]);
			a = liquid[i], b = liquid[i + 1];
		}
	cout << a << " " << b;
}