#include <iostream>
#include <cstring>
using namespace std;
int selfNum(int start, int end) {
	bool self[100000];
	memset(self, true, sizeof(self));
	int sum, num;
	for (int i = 1; i <= end; i++) {
		sum = i, num = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		self[sum] = false;
	}
	sum = 0;
	for (int i = start; i <= end; i++) {
		if (self[i]) sum += i;
	}
	return sum;
}
int main() {
	int start, end;
	cin >> start >> end;
	cout << selfNum(start, end);
}