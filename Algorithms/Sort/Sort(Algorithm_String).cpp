#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.length() < b.length())
		return 1;
	else if (a.length() > b.length())
		return 0;
	else
		return a < b;
}
int main() {
	string a[20000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) continue;
		cout << a[i] << '\n';
	}
}