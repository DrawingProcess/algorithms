#include <iostream>
#include <string>
using namespace std;
int main() {
	string str, y, m, d, g;
	cin >> str;
	y = str.substr(0, 2);
	m = str.substr(2, 2);
	d = str.substr(4, 2);
	if (str[7] == '1') {
		y = "19" + y;
		g = "M";
	}
	else if (str[7] == '2') { 
		y = "19" + y;
		g = "F";
	}
	else if (str[7] == '3') { 
		y = "20" + y;
		g = "M";
	}
	else if (str[7] == '4') { 
		y = "20" + y;
		g = "F";
	}
	cout << y + "/" + m + "/" + d + " " + g;
}