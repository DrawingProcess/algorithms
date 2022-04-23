#include <iostream>
using namespace std;
int main() {
	int X, N, num, A[10000];
	cin >> N >> X;
	if ((1 <= N && N <= 10000) && (1 <= X && X <= 10000)){
		for (int i = 0; i < N; i++) {
			cin >> num;
			if (X > num)
				A[i] = num;
			else
				A[i] = NULL; // 빈공간
		}
		for (int i = 0; i < N; i++) {
			if (A[i] != NULL) // 빈공간이면 출력하지 않음.
				cout << A[i] << ' ';
		}
	}
}