#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string a;
	cin >> a;
	int d, s;
	d = stoi(a.substr(0, a.find("-")));
	s = stoi(a.substr(a.find("-")+1));
	cout << setfill('0') << setw(6) << d;
	cout << setfill('0') << setw(7) << s;
}