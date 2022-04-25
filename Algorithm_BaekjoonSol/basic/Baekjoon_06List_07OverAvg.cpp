#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int sub, sum = 0, count = 0;
		cin >> sub;
		int* score = new int[sub];
		for (int j = 0; j < sub; j++) {
			cin >> score[j];
			sum += score[j];
		}
		for (int i = 0; i < sub; i++) {
			if (sum / sub < score[i])
				count++;
		}
		cout.precision(3);
		cout << fixed << (double) count / sub * 100 << '%' << '\n';
		delete[] score;
	}
}