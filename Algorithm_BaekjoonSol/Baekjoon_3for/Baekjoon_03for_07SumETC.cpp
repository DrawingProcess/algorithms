#include <iostream>
using namespace std;
int main() {
	int num, fir, sec, sum[100];
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> fir >> sec;
		if ((0 < fir && fir < 10) && (0 < sec && sec < 10)) {
			sum[i] = fir + sec;
		}
	}
	for (int i = 1; i <= num; i++)
		cout << "Case #" << i << ": " << sum[i] << '\n';
}