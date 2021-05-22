#include <iostream>
#include <string>
using namespace std;
int main() {
	int num;
	string binary;
	cin >> num;
	int toBinary = num;
	while (toBinary != 0) {
		binary = to_string(toBinary % 2) + binary;
		toBinary /= 2;
	}
	cout << 2 << " " << binary << "\n";
	cout << dec << 8 << " " << oct << num << "\n";
	cout << dec << 16 << " " << hex << uppercase << num << "\n";
}