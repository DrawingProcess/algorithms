#include <iostream>
//#include <cstdlib>
using namespace std;

int main() {
	int num, sum = 0;
	cin >> num;
	char eachNum;
	if (1 <= num && num <= 100) {
		for (int i = 1; i <= num; i++) {
			cin >> eachNum;
			sum += eachNum - 48; // sum += atoi(&eachNum); atoi(char*) -> char to int
		}
		cout << sum;
	}
}