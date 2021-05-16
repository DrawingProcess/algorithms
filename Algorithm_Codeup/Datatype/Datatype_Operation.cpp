#include <iostream>
using namespace std;
int main() {
	unsigned long long n1, n2;
	cin >> n1 >> n2;
	cout << n1 + n2 << "\n"; // 합
	cout << n1 - n2 << "\n"; // 차
	cout << n1 * n2 << "\n"; // 차
	cout << n1 / n2 << "\n"; // 몫
	cout << n1 % n2 << "\n"; // 나머지
	cout << fixed; // 정수더라도 precision만큼 0생성
	cout.precision(2);
	cout << (float)n1 / (float)n2 << "\n"; // 나눈 값
}