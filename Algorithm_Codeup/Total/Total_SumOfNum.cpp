#include <iostream>
using namespace std;
int main() {
	//// ��������
	//int num, d, n;
	//cin >> num >> d >> n;
	//int cnt = num;
	//n--;
	//while (n != 0) {
	//	cnt += d;
	//	n--;
	//}
	//cout << cnt;

	// ������
	//int num, d, n;
	//cin >> num >> d >> n;
	//long long cnt = num;
	//n--;
	//while (n != 0) {
	//	cnt *= d;
	//	n--;
	//}
	//cout << cnt;

	// ����������
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