#include <iostream>
#include <string>
#include <algorithm>	// for transform(for upper)
using namespace std;

int main() {
	string str;
	int array[26] = { }, max = 0, index;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for (int i = 0; i < str.length(); i++) {
		if (65 <= str[i] && str[i] <= 90) {
			array[str[i] - 65]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (array[i] > max) {
			max = array[i];
			index = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == array[i] && i != index) {
			cout << "?\n";
			return 0;
		}
	}
	char ASCII = index + 65;
	cout << ASCII << endl;
}