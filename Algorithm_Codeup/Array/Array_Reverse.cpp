#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> save;
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		save.push_back(t);
	}
	while (save.size() != 0) {
		cout << save.back() << " ";
		save.pop_back();
	}
}