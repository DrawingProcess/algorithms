#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}
int main() {
	vector<pair<string, int>> grades;
	string str;
	int num, score;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> str >> score;
		grades.push_back(make_pair(str, score));
	}
	sort(grades.begin(), grades.end(), cmp);
	cout << grades[2].first;
}