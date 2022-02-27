#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> divisor;
	int num, k;
	cin >> num >> k;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0)
			divisor.push_back(i);
	}
	divisor.push_back(num);
	cout << divisor[k - 1];
}