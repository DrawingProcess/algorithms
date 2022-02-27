#include <iostream>
using namespace std;

#define INF 987654321

const int n = 10;
int ready[n], value[n];
int coins[] = { 1,3,4 };
// ������ using recursion(solve function)
int solve(int x) {
	if (x < 0) return INF;
	if (x == 0) return 0;
	if (ready[x]) return value[x];
	int best = INF;
	for (auto c : coins) {
		best = min(best, solve(x - c) + 1);
	}
	ready[x] = true;
	value[x] = best;
	return best;
}
int main() {
	// ������ using recursion(solve function)
	for (int i = 0; i < 10; i++)
		cout << solve(i) << "\t";
	cout << "\n";

	// ������ using iteration
	value[0] = 0;
	for (int x = 1; x <= n; x++) {
		value[x] = INF;
		for (auto c : coins) {
			if (x - c >= 0) {
				value[x] = min(value[x], value[x - c] + 1);
			}
		}
	}
	for (int x = 0; x < n; x++) {
		cout << value[x] << "\t";
	}
	cout << "\n";

	// ������ + �����ؿ� ���Ǵ� ���� ���
	int first[n+1]; // first: �������� ���� ������ memorization�� ��
	value[0] = 0;
	for (int x = 1; x <= n; x++) {
		value[x] = INF;
		for (auto c : coins) {
			if (x - c >= 0 && value[x - c] + 1 < value[x]) {
				value[x] = value[x - c] + 1;
				first[x] = c;
			}
		}
	}
	int cnt = n;
	while (cnt > 0) { // cnt: ������ ���� ���� ���Ǵ� ����
		cout << first[cnt] << "\t";
		cnt -= first[cnt];
	}
	cout << "\n";
	
	//// �� x�� ����� ����� ���� ��
	//int count[n+1];
	//count[0] = 1;
	//for (int x = 1; x <= n; x++) {
	//	for (auto c : coins) {
	//		if (x - c >= 0) {
	//			count[x] += count[x - c];
	//			//count[x] %= 900000000; // ���� �ʹ� Ŭ��� �������� �����.
	//		}
	//	}
	//}
	//for (int i = 0; i < 10; i++)
	//	cout << count[i] << "\t";
	//cout << "\n";
}