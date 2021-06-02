#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;\

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second > b.second;
}

int main() {
	vector<pair<pair<int, int>, int> > result, sol;
	int country, num, score, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> country >> num >> score;
		result.push_back(make_pair(make_pair(country, num), score));
	}
	sort(result.begin(), result.end(), cmp);
	int before = 0, cnt = 1;
	sol.push_back(result[0]);
	for (int i = 1; i < n; i++) {
		if (sol.size() == 3) break;
		if (sol[before].first.first == result[i].first.first) {
			cnt++;
			if (cnt == 3) continue;
		}
		sol.push_back(result[i]);
		before = i;
	}
	for (int i = 0; i < 3; i++) {
		cout << sol[i].first.first << " " << sol[i].first.second << "\n";
	}
}