#include <iostream>
using namespace std;

// for bitset
#include <bitset>

int main() {
	int x = 5328;
	// bit mask
	for (int k = 31; k >= 0; k--) {
		if (x & (1 << k)) cout << "1";
		else cout << "0";
	}

	cout << __builtin_clz(x) << "\n";	// ��Ʈǥ������ ���ʿ� �����ؼ� �ִ� ��Ʈ 0�� ����
	cout << __builtin_ctz(x) << "\n";	// ��Ʈǥ������ �����ʿ� �����ؼ� �ִ� ��Ʈ 0�� ����
	cout << __builtin_popcount(x) << "\n";	// ��Ʈ ǥ������ ��Ʈ 1�� ����

	// set
	int x = 0;
	x |= (1 << 1);
	x |= (1 << 3);
	x |= (1 << 4);
	x |= (1 << 8);
	// int x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8)
	cout << __builtin_popcount(x) << "\n"; // 4
	for (int i = 0; i < 32; i++)
		if (x & (1 << i)) cout << i << " "; // 1 3 4 8

	// bitset
	bitset<10> s;
	s[1] = 1;
	s[3] = 1;
	s[4] = 1;
	s[8] = 1;
	cout << s.count() << "\n"; // 4
}