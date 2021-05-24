#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void heapSort(vector<int>& arr) {
	priority_queue<int> h;
	for (int i = 0; i < arr.size(); i++)
		h.push(-arr[i]); // 오름차순 VS 내림차순(+)
	while (!h.empty()) {
		cout << -h.top() << "\n";
		h.pop();
	}
}
int main() {
	vector<int> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	heapSort(arr);
}