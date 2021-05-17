#include <iostream>
using namespace std;
int main() {
	int save[24] = { 0, };
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		save[t]++;
	}
	for (int i = 1; i < 24; i++) {
		cout << save[i] << " ";
	}
}