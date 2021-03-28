#include <iostream>
#include <vector>
using namespace std;

vector<int> permutation;
const int n = 100;
bool chosen[n + 1];

// i)
void search() {
	if (permutation.size() == n) {
		// 순열 처리과정
		for (int j = 0; j <= n; j++)
			cout << permutation[j] << '\t';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

// ii)
do {
	// 순열 처리과정
	for (int j = 0; j <= n; j++)
		cout << permutation[j] << '\t';
} while (next_permutation(permutation.begin(), permutation.end()));