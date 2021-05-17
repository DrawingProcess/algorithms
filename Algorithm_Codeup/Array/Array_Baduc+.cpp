#include <iostream>
using namespace std;
int main() {
	int baduc[20][20] = { 0, };
	int num, r, c;
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			cin >> baduc[i][j];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> r >> c;
		for (int j = 1; j <= 19; j++) {
			if (baduc[r][j]) baduc[r][j] = 0;
			else baduc[r][j] = 1;
		}
		for (int j = 1; j <= 19; j++) {
			if (baduc[j][c]) baduc[j][c] = 0;
			else baduc[j][c] = 1;
		}
	}
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++)
			cout << baduc[i][j] << " ";
		cout << "\n";
	}
}