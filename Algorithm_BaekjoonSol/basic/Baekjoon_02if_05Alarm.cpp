#include <iostream>
//#include <iomanip> // �ð����

using namespace std;
int main() {
	int H, M;
	cin >> H >> M;
//	cout.fill('0'); // �ð� : ���ڸ����� ��� setw�� 2�ڸ� ������ �Ҵ��ϰ� fill('0')�� ����� '0'���� ä���
//	cout << setw(2) << H << ':' << setw(2) << M << endl;
	if ((0 <= H && H <= 23) && (0 <= M && M <= 59)) {
		if (M - 45 < 0) {
			if (H - 1 < 0)
				cout << 24 + (H - 1) << ' ' << 60 + (M - 45);
			else if (H - 1 >= 0)
				cout << H - 1 << ' ' << 60 + (M - 45);
		}
		else if (M - 45 >= 0)
			cout << H << ' ' << M - 45;
	}
}