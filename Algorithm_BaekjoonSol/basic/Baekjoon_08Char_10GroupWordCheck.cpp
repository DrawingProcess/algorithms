#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int num, word = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		bool total = false;
		int arr[26] = {};
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (arr[str[j] - 97] == -1) {
				if (str[j - 1] != str[j]) {
					total = true;
					break;	// 그룹단어가 아닐경우
				}
			}
			arr[str[j] - 97] = -1;
		}
		if (total == true)
			continue;
		word++;
	}
	cout << word;
}