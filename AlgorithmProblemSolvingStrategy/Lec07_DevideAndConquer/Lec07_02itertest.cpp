
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	vector<int> v;
	v.push_back(4);
	v.push_back(9);
	v.push_back(17);

	vector<int>::iterator p = v.begin();
	int head = *(++p);
	cout << head << endl;
	cout << *(p) << endl;
	head = *(p++);
	//cout << head << endl;
	//cout << *(p) << endl;
	//cout << *(p+1) << endl;
	while (p != v.end()) {
		cout << *(p++) << endl;
	}

	// REF : https://www.techiedelight.com/convert-char-to-string-cpp/
	char tab = 'tab';
	string str = string(5, tab); // constructor string (size_t n, char c) : which files the string with n copies of charactor c.
	cout << tab << endl; // b
	cout << str << endl; // bbbbb

	return 0;
}