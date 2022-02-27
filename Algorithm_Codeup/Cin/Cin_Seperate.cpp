#include <iostream>
using namespace std;

int main() {
	char input[20];
	cin.getline(input, 20);
	for (int i = 0; input[i] != '\0'; i++) {
		cout << '\'' << input[i] << '\'' << endl;
	}
}