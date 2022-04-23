#include <iostream>
//#include <iomanip> // 시계출력

using namespace std;
int main() {
	int H, M;
	cin >> H >> M;
//	cout.fill('0'); // 시계 : 한자리수일 경우 setw로 2자리 공간에 할당하고 fill('0')로 빈공간 '0'으로 채우기
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