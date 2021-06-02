#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> scores;
	int num, score;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> score;
		scores.push_back(score);
	}
	sort(scores.begin(), scores.end());
	cout << scores[scores.size() - 1] - scores[0];
}