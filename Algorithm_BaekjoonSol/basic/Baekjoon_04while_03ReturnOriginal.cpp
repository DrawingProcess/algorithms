#include <iostream>
using namespace std;

int main() {
	int num, renum = 0, fir, sec, n = 0, numCal;
	cin >> num;
	numCal = num;
	if (0 <= num && num <= 99) {
		while (true) {
			fir = numCal % 10;
			sec = numCal / 10 + (numCal % 10);
			renum = fir * 10 + (sec % 10);
			if (num == renum)
				break;
			numCal = renum;
			n++;
		}
		cout << n+1;
	}
}