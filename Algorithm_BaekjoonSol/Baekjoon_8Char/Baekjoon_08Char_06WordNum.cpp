#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int pos, word = 0;
	getline(cin, str);
	//cin.setf(ios::skipws); // space도 입력으로 생각하게 함(skip white space)
	//cin >> str;
	if (!str.empty()) {
		if (str.front() == ' ')
			str.erase(str.begin());
		if (!str.empty()) {
			if (str.back() == ' ')
				str.erase(str.end() - 1);
			pos = str.find(' ');
			while (pos != str.npos) {
				word++;
				pos = str.find(' ', pos + 1);
			}
			word++;
			//for (int i = 0; i < str.length(); i++) {
			//	if (str[i] == ' ')
			//		word++;
			//}
			//word++;
		}
	}
	cout << word;
}