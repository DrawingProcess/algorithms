#include <iostream>
using namespace std;
int main() {
	int h, m, s, time;
	cin >> h >> m >> s >> time;
	s = s + time;
	while (s >= 60) {
		s -= 60;
		m++;
	}
	while (m >= 60) {
		m -= 60;
		h++;
	}
	h %= 24;
	cout << h << " " << m << " " << s;
}