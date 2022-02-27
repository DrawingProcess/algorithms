#include <iostream>
using namespace std;
int main() {
	double start, end, sub, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> start >> end;
		sub = end - start - 1 > 0 ? end - start - 1 : 0;
		if (sub < 0) sub = 0;
		else if (sub > 4) sub = 4;
		sum += sub;
	}
	if (sum >= 15) sum *= 0.95;
	else if (sum <= 5) sum *= 1.05;
	cout << sum * 10000;
}