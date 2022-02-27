#include <iostream>
using namespace std;

int n;
bool areFriends[10][10];
int countPairings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	
	// base case
	if (firstFree == -1) return 1;

	// if find pairs
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int pairNum;
		cin >> n >> pairNum;
		memset(areFriends, 0, sizeof(areFriends));
		for (int i = 0; i < pairNum; i++) {
			int r, c;
			cin >> r >> c;
			areFriends[r][c] = areFriends[c][r] = true;
		}
		bool taken[10] = { 0, };
		cout << countPairings(taken) << "\n";
	}
}