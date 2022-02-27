#include <iostream>
#include <algorithm>
using namespace std;

int seq[3];
void solve(int cur, int depth) {
	if (depth == 3) {
		for (int i = 0; i < 3; i++)
			cout << seq[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = cur; i < 5; i++) {
			seq[depth] = i;
			solve(i, depth + 1);
		}
	}
}
int main() {
	// 조합
	int arr[5] = { 0, 0, 1, 1, 1 };
	do {
		for (int i = 0; i < 5; i++) {
			if (arr[i]) cout << "i+1" << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, arr + 5));
	cout << "\n\n";

	// 순열
	int arr[5] = { 0, 0, 1, 2, 3 };
	do {
		for (int i = 0; i < 5; i++) {
			if (arr[i]) cout << "i+1" << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, arr + 5));
	cout << "\n\n";

	// 중복 조합
	solve(1, 0);

	// 중복 순열
	int mask = 5 * 5 * 5;
	for (int mask = 0; mask < 5 * 5 * 5; mask++) {
		int tmp = mask;
		for (int i = 0; i < 3; i++) {
			cout << tmp % 5 + i;;
			tmp /= 5;
		}
		cout << "\n";
	}
}