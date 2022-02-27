#include <iostream>
#include <string>
using namespace std;
int main() {
	string numR;
	int num, sum = 0;
	cin >> num;
	while (num != 0) {
		sum += num % 10;
		numR += to_string(num % 10);
		num /= 10;
	}
	cout << stoi(numR) << "\n" << sum;
}