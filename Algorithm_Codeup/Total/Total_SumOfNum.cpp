#include <iostream>
using namespace std;
int main() {
	//// 등차수열
	//int num, d, n;
	//cin >> num >> d >> n;
	//int cnt = num;
	//n--;
	//while (n != 0) {
	//	cnt += d;
	//	n--;
	//}
	//cout << cnt;

	// 등비수열
	//int num, d, n;
	//cin >> num >> d >> n;
	//long long cnt = num;
	//n--;
	//while (n != 0) {
	//	cnt *= d;
	//	n--;
	//}
	//cout << cnt;

	// 등차등비수열
	int num, m, d, n;
	cin >> num >> m >> d >> n;
	long long cnt = num;
	n--;
	while (n != 0) {
		cnt = cnt * m + d;
		n--;
	}
	cout << cnt;
}