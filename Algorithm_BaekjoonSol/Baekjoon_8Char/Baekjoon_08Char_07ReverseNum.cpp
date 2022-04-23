#include <iostream>
#include <string>
#include <algorithm>	// reverse
using namespace std;

int main() {
	int large;
	string str1, str2, str1R, str2R;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	large = stoi(str1) > stoi(str2) ? stoi(str1) : stoi(str2);
	// string out of range
	//for (int i = 0; i < str1.length(); i++) {
	//	str1R.push_back(str1[str1.back() - i]);
	//} 
	//for (int i = 0; i < str2.length(); i++) {
	//	str2R.push_back(str2[str2.back() - i]);
	//}
	//large = stoi(str1R) > stoi(str2R) ? stoi(str1R) : stoi(str2R);
	cout << large << endl;
}