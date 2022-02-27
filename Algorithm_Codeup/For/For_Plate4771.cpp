#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	char before = str[0];
	int sum = 10;
	for (int i = 1; i < str.size(); i++) {
		if (before == str[i]) sum += 5;
		else sum += 10;
		before = str[i];
	}
	cout << sum;
}