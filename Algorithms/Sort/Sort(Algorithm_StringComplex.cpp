#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	else {
		int countA = 0, countB = 0;
		for (int i = 0; i < a.length(); i++) {
			if ('0' <= a[i] && a[i] <= '9')
				countA += int(a[i] - '0');
			if ('0' <= b[i] && b[i] <= '9')
				countB += int(b[i] - '0');
		}
		if (countA != countB)
			return countA < countB;
		else
			return a < b;
	}
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