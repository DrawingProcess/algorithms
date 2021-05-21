#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> v;
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	v.push_back(n1);
	v.push_back(n2);
	v.push_back(n3);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}