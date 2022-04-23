#include <iostream>
using namespace std;

int main() {
	int Alpha[26] = {};
	for (int i = 0; i < 26; i++)
		Alpha[i]--;
	char S[100];
	cin >> S;
	for (int i = 0; i < 100; i++) {
		if (Alpha[S[i] - 97] == -1)
			Alpha[S[i] - 97] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << Alpha[i] << ' ';
}
/*
#include<iostream>
using namespace std;

int main() {
	string s;
	string abc = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	for(int i = 0; i < abc.length(); i++){
		if(s.find(abc[i]) == string::npos)
			cout << -1 << " ";
		else{
			cout << s.find(abc[i]) << " ";
			continue;
		}
	}
}
*/