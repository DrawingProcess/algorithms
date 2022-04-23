#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int time = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 67)
			time += 3;
		else if (str[i] >= 68 && str[i] <= 70)
			time += 4;
		else if (str[i] >= 71 && str[i] <= 73)
			time += 5;
		else if (str[i] >= 74 && str[i] <= 76)
			time += 6;
		else if (str[i] >= 77 && str[i] <= 79)
			time += 7;
		else if (str[i] >= 80 && str[i] <= 83)
			time += 8;
		else if (str[i] >= 84 && str[i] <= 86)
			time += 9;
		else if (str[i] >= 87 && str[i] <= 90)
			time += 10;
	}
	cout << time << endl;
}