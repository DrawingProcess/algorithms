#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack<int> stk;
	int num, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) stk.pop();
		else stk.push(num);
	}
	int sum = 0;
	while(!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}
	cout << sum;
}