#include <iostream>
//#include <cstring>
using namespace std;

int main() {
	int num, sum, part;
	cin >> num;

	for (int i = 1; i < num; ++i) {
		sum = i;
		part = i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (num == sum) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}

////sol
//int main() {
//	int n, m, digit = 0;
//	cin >> n;
//	m = n;
//	while (m) {
//		m /= 10;
//		digit++;
//	}
//	// 분해합은 최소 n - 9*n의 자릿수 부터 시작
//	int begin = n - digit * 9;
//	char s[10];
//	int sum = 0;
//	bool find = false;
//	for (int i = begin; i <= n; ++i)
//	{
//		sprintf_s(s, "%d", i);
//		sum = i;
//		for (int j = 0; j < strlen(s); ++j)
//			sum += s[j] - '0';
//		if (sum == n)
//		{
//			find = true;
//			cout << i << "\n";
//			break;
//		}
//	}
//	if (find == false)	cout << "0\n";
//
//	return 0;
//}