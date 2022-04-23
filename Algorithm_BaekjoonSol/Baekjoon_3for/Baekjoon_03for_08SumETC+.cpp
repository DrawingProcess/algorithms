#include <iostream>
using namespace std;
int main() {
	int num, fir[100], sec[100], sum[100];
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> fir[i] >> sec[i];
		if ((0 < fir[i] && fir[i] < 10) && (0 < sec[i] && sec[i] < 10)) {
			sum[i] = fir[i] + sec[i];
		}
	}
	for (int i = 1; i <= num; i++)
		cout << "Case #" << i << ": " << fir[i] << " + " << sec[i] << " = " << sum[i] << '\n';
}