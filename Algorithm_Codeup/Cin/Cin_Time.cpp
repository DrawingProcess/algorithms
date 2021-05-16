#include <iostream>
#include <string>
using namespace std;
int main() {
	string a;
	cin >> a;
	int h, m;
	h = stoi(a.substr(0, a.find(":")));
	m = stoi(a.substr(a.find(":")+1));
	cout << h << ":" << m;
}