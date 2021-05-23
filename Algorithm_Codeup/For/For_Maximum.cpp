#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> numsO, numsE;
	int num;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) numsO.push_back(num);
		else if (num % 2 == 0) numsE.push_back(num);
	}
	if (numsO.empty()) {
		sort(numsE.begin(), numsE.end());
		cout << numsE[numsE.size() - 1];
	}
	else if (numsE.empty()) {
		sort(numsO.begin(), numsO.end());
		cout << numsO[numsO.size() - 1];
	}
	else {
		sort(numsO.begin(), numsO.end());
		sort(numsE.begin(), numsE.end());
		cout << numsO[numsO.size() - 1] + numsE[numsE.size() - 1];
	}
}