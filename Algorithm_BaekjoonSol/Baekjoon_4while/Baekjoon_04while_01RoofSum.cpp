#include <iostream>
using namespace std;
int main() {
	int fir, sec, n = 0, sum[100];
	while (true) {
		cin >> fir >> sec;
		if ((fir == 0 && sec == 0) || ((0 >= fir && fir >= 10) && (0 >= sec && sec <= 10)))
			break;
		else
			sum[n] = fir + sec;
		n++;
	}
	for (int i = 0; i < n; i++)
		cout << sum[i] << '\n';
	return 0;
}