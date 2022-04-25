#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int num = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-') {
			if (str[i - 1] == 'c' || str[i - 1] == 'd') {
				continue;	// c- or d-
			}
		}
		else if (str[i] == '=') {
			if (str[i - 1] == 'z') {
				if (str[i - 2] == 'd') {
					num--;
					continue;	// dz=
				}
			}
			continue;	// c= or s= or z=
		}
		else if (str[i] == 'j') {
			if (str[i - 1] == 'l' || str[i - 1] == 'n') {
				continue;	// lj or nj
			}
		}
		num++;
	}
	cout << num;
}