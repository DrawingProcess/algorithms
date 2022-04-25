#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int num;
	char OX[80];
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> OX;
		int sum = 0, Accumulate = 1;
		for (unsigned j = 0; j < strlen(OX); j++){
			if (OX[j] == 'O') {
				sum += Accumulate;
				Accumulate++;
			}
			else
				Accumulate = 1;
		}
		cout << sum << '\n';
	}
}