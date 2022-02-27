#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack<int> stk;
	string s, n;
	int num, pu;
	cin >> num;
	for (int i = 0; i <= num; i++) {
		getline(cin, s);
		if (s[0] == 'p') {
			if (s[1] == 'u') stk.push(stoi(s.substr(6, s.find(' ', 6))));
			else if (s[1] == 'o' && !stk.empty()) stk.pop();
		}
		else if (s[0] == 't') {
			if (stk.empty()) cout << -1 << "\n";
			else cout << stk.top() << "\n";
		}
		else if (s[0] == 's') cout << stk.size() << "\n";
		else if (s[0] == 'e') {
			if (stk.empty()) cout << "true" << "\n";
			else cout << "false" << "\n";
		}
	}
}