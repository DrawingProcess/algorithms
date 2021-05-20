#include <iostream>
using namespace std;
//1MB = 1,000,000바이트
//int자료형 = 4바이트

//우박수의 길이를 기억하는 배열
int hailLengths[100000000];
int bigHailIndex = 0;
long long int f(long long int n, long long int length) {
	if (n < 99999999)
		//만약 이 우박수의 최종 길이를 알고 있다면
		if (hailLengths[n])
			//지금까지의 길이와 이 우박수의 최종 길이를 더해 리턴한다
			return length + hailLengths[n];
	length++;
	//짝수일 경우
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
		//우박수의 길이를 기억시킨다 
		hailLengths[i] = f(i, 0);
		if (hailLengths[bigHailIndex] < hailLengths[i])
			bigHailIndex = i;
	}
	cout << bigHailIndex << " " << hailLengths[bigHailIndex];
}