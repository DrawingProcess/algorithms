#include <iostream>
#include <vector>
using namespace std;
int main() {
	string nums;
	int num, n;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n;
		nums.push_back(n);
	}
	while (!nums.empty()) {
		cout << nums.back() << " ";
		nums.pop_back();
	}
}