#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string a;
	cin >> a;
	int h, m, s;
	h = stoi(a.substr(0, a.find(":")));
	m = stoi(a.substr(a.find(":") + 1, a.find(":", a.find(":") + 1)));
	s = stoi(a.substr(a.find(":", a.find(":") + 1) + 1));
	cout << m;
}