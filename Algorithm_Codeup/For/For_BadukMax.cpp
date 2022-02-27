#include <iostream>
using namespace std;
int main() {
	int max = 0, baduk[10][10], max_i, max_j;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> baduk[i][j];
			if (max < baduk[i][j]) {
				max = baduk[i][j];
				max_i = i + 1, max_j = j + 1;
			}
		}
	}
	cout << max << "\n" << max_i << " " << max_j;
}