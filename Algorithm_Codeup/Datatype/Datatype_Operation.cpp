#include <iostream>
using namespace std;
int main() {
	unsigned long long n1, n2;
	cin >> n1 >> n2;
	cout << n1 + n2 << "\n"; // ��
	cout << n1 - n2 << "\n"; // ��
	cout << n1 * n2 << "\n"; // ��
	cout << n1 / n2 << "\n"; // ��
	cout << n1 % n2 << "\n"; // ������
	cout << fixed; // �������� precision��ŭ 0����
	cout.precision(2);
	cout << (float)n1 / (float)n2 << "\n"; // ���� ��
}