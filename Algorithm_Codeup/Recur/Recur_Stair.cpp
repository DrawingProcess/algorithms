#include <iostream>
using namespace std;

int stair[100001] = { 1, 1, 2 };

int recur(int a) {
	if (a == 1) return 1;
	if (stair[a]) return stair[a];
	else return stair[a] = (recur(a - 3) + recur(a - 2) + recur(a - 1)) % 1000;
}

int main() {
	int num;
	cin >> num;
	cout << recur(num);
	return 0;
}