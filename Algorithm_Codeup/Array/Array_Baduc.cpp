#include <iostream>
using namespace std;
int main() {
	int baduc[20][20] = { 0, };
	int num, r, c;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> r >> c;
		baduc[r][c] = 1;
	}
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++)
			cout << baduc[i][j] << " ";
		cout << "\n";
	}
}