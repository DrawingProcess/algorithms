#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	int num, pre = 0;
	cin >> a >> b;
	if (a.size() > b.size()) {
		for (int i = 0; i < b.size(); i++) {
			num = a[a.size() - i - 1] - '0' + b[b.size() - i - 1] - '0' + pre;
			if (num >= 10) {
				a[a.size() - i - 1] += b[b.size() - i - 1] - '0' - 10 + pre;
				pre = 1;
			}
			else {
				a[a.size() - i - 1] += b[b.size() - i - 1] - '0' + pre;
				pre = 0;
			}
		}
		int cnt = 0;
		while (pre == 1 && a.size() > a.size() - b.size() - 1 - cnt) {
			num = a[a.size() - b.size() - 1 - cnt] - '0' + pre;
			if (num >= 10) {
				a[a.size() - b.size() - 1 - cnt] += pre - 10;
				pre = 1;
			}
			else {
				a[a.size() - b.size() - 1 - cnt] += pre;
				pre = 0;
			}
			cnt++;
		}
		if (pre == 1) a = "1" + a;
		cout << a;
	}
	else {
		for (int i = 0; i < a.size(); i++) {
			num = b[b.size() - i - 1] - '0' + a[a.size() - i - 1] - '0' + pre;
			if (num >= 10) {
				b[b.size() - i - 1] += a[a.size() - i - 1] - '0' - 10 + pre;
				pre = 1;
			}
			else {
				b[b.size() - i - 1] += a[a.size() - i - 1] - '0' + pre;
				pre = 0;
			}
		}
		int cnt = 0;
		while (pre == 1 && b.size() > b.size() - a.size() - 1 - cnt) {
			num = b[b.size() - a.size() - 1 - cnt] - '0' + pre;
			if (num >= 10) {
				b[b.size() - a.size() - 1 - cnt] += pre - 10;
				pre = 1;
			}
			else {
				b[b.size() - a.size() - 1 - cnt] += pre;
				pre = 0;
			}
			cnt++;
		}
		if (pre == 1) b = "1" + b;
		cout << b;
	}
}