#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string a;
	cin >> a;
	int y, m, d;
	y = stoi(a.substr(0, a.find(".")));
	m = stoi(a.substr(a.find(".") + 1, a.find(".", a.find(".") + 1)));
	d = stoi(a.substr(a.find(".", a.find(".") + 1) + 1));
	cout << setfill('0') << setw(2) << d;
	cout << "-";
	cout << setfill('0') << setw(2) << m;
	cout << "-";
	cout << setfill('0') << setw(4) << y;
}