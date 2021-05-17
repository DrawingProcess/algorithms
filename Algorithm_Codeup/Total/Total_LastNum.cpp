#include <iostream>
using namespace std;
int main() {
	int num, sum = 0, cnt = 0;
	cin >> num;
	while (sum < num) {
		cnt++;
		sum += cnt;
	}
	cout << cnt;
}