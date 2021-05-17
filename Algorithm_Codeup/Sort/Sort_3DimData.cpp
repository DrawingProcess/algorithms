#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		if (a.second.second == b.second.second) {
			return a.first < b.first;
		}
		else return a.second.second > b.second.second;
	}
	else return a.second.first > b.second.first;
}
int main() {
	vector<pair<int, pair<int, int>>> grades;
	pair<int, int> score;
	int num, a, b;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		score = make_pair(a, b);
		grades.push_back(make_pair(i + 1, score));
	}
	sort(grades.begin(), grades.end(), cmp);
	for (int i = 0; i < grades.size(); i++) {
		cout << grades[i].first << " " << grades[i].second.first << " " << grades[i].second.second << "\n";
	}
}