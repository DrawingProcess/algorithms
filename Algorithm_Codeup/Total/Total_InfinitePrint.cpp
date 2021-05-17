#include <iostream>
using namespace std;
int main() {
	char chr;
	while (cin >> chr) {
		cout << chr << "\n";
		if (chr == 'q') break;
	}
}