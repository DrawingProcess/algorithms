#include <iostream>
using namespace std;
int main() {
	int num, fir, sec, sum[1000000];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> fir >> sec;
		if ((1 <= fir && fir <= 1000) && (1 <= sec && sec <= 1000)) {
			sum[i] = fir + sec;
		}
	}
	for (int i = 0; i < num; i++)
		cout << sum[i] << '\n';
}