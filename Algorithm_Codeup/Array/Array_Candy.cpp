#include <iostream>
using namespace std;
int main() {
	int r, c, num, l, d, x, y;
	cin >> r >> c >> num;
	int** matrix = new int*[r];
	for (int i = 0; i < r; i++)
		matrix[i] = new int[c];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			matrix[i][j] = 0;

	for (int i = 0; i < num; i++) {
		cin >> l >> d >> x >> y;
		if (d == 0) {
			for (int i = 0; i < l; i++)
				matrix[x - 1][y - 1 + i] = 1;
		}
		else
			for (int i = 0; i < l; i++)
				matrix[x - 1 + i][y - 1] = 1;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
	for (int i = 0; i < r; i++)
		delete[] matrix[i];
	delete[] matrix;
}