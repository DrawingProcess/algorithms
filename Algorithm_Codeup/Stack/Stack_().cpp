#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack<char> parentheses;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') parentheses.push(s[i]);
		else if (s[i] == ')') {
			if (parentheses.empty()) {
				cout << "bad";
				return 0;
			}
			parentheses.pop();
		}
	}
	if (parentheses.empty()) cout << "good";
	else cout << "bad";
}