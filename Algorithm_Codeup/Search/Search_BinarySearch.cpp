#include <iostream>
using namespace std;
int BinarySearch(int arr[], int size, int item);
int main() {
	int D = 0;
	int num1[1000000] = { 0, };
	int num2[100000] = { 0, };
	int q = 0;
	cin >> D;
	for (int i = 0; i < D; i++)
		cin >> num1[i];
	cin >> q;
	for (int i = 0; i < q; i++)
		cin >> num2[i];
	for (int i = 0; i < q; i++) {
		int t = BinarySearch(num1, D, num2[i]);
		if (t > -1) { cout << t + 1 << " "; }
		else { cout << t << " "; }
	}
}

int BinarySearch(int arr[], int size, int item) {
	int first = 0;
	int last = size - 1;
	int mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (arr[mid] == item) { return mid; }
		else {
			if (item > arr[mid]) { first = mid + 1; }
			else { last = mid - 1; }
		}
	}
	return -1;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool cmp(pair<int, int> a, pair<int, int> b) {
//	return a.second < b.second;
//}
//int main() {
//	vector<int> N;
//	vector<pair<int, int> > M;
//	int n, m, num, result[100002] = { -2 ,};
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		N.push_back(num);
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> num;
//		M.push_back(make_pair(i, num));
//	}
//	sort(M.begin(), M.end(), cmp);
//	int i = 0, j = 0;
//	while (true) {
//		if (i == N.size() || j == M.size()) break;
//		if (N[i] < M[j].second) i++;
//		else if (N[i] > M[j].second) {
//			result[M[j].first] = -1;
//			j++;
//		}
//		else { // N[i] = M[j].second
//			result[M[j].first] = i + 1;
//			i++;
//			j++;
//		}
//	}
//	for (int i = 0; i < M.size(); i++) {
//		cout << result[i] << " ";
//	}
//}