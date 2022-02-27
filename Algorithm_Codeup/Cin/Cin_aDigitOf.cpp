#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int nums[5];
	int num, cnt = 0;
	cin >> num;
	while (num != 0) {
		nums[cnt] = num % 10;
		num /= 10;
		cnt++;
	}
	for (int i = cnt-1; i >= 0; i--) {
		cout << "[" + to_string(nums[i] * int(pow(10, i))) + "]\n";
	}
}