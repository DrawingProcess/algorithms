#include <iostream>
using namespace std;
//1MB = 1,000,000����Ʈ
//int�ڷ��� = 4����Ʈ

//��ڼ��� ���̸� ����ϴ� �迭
int hailLengths[100000000];
int bigHailIndex = 0;
long long int f(long long int n, long long int length) {
	if (n < 99999999)
		//���� �� ��ڼ��� ���� ���̸� �˰� �ִٸ�
		if (hailLengths[n])
			//���ݱ����� ���̿� �� ��ڼ��� ���� ���̸� ���� �����Ѵ�
			return length + hailLengths[n];
	length++;
	//¦���� ���
	if (n % 2 == 0)
		return f(n / 2, length);
	else
		return f(n * 3 + 1, length);
}

int main() {
	int min, max;
	cin >> min >> max;

	hailLengths[1] = 1;
	int n;
	for (int i = min; i <= max; i++) {
		//��ڼ��� ���̸� ����Ų�� 
		hailLengths[i] = f(i, 0);
		if (hailLengths[bigHailIndex] < hailLengths[i])
			bigHailIndex = i;
	}
	cout << bigHailIndex << " " << hailLengths[bigHailIndex];
}