#include <iostream>
#include <string>
using namespace std;

int main() {
	int iter, num;
	string str;
	cin >> iter;
	for (int i = 0; i < iter; i++) {
		cin >> num;
		cin >> str;
		for (int k = 0; k < str.length(); k++) {
			for (int j = 0; j < num; j++) {			
				cout << str[k];
			}
		}
		cout << endl;
	}
}