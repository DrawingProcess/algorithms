#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
double ABS(double n) {
	stringstream ss;
	ss << fixed << setprecision(0) << n;
	string str = ss.str();
	if (str.find('.') != std::string::npos) {
		// Remove trailing zeroes
		str = str.substr(0, str.find_last_not_of('0') + 1);
		// If the decimal point is now the last character, remove that as well
		if (str.find('.') == str.size() - 1){
			str = str.substr(0, str.size() - 1);
		}
	}
	n = stod(str);
	if (n < 0) return -n;
	return n;
}
int main() {
	double n;
	cin >> n;
	cout << ABS(n);
}