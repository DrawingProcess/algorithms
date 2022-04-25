#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int n3 = 0;
    int n5 = 0;
    while (N % 5 != 0 && N >= 0) {
        N -= 3;
        n3++;
    }
    if (N < 0) cout << -1 << endl;
    else {
        n5 = N / 5;
        cout << n3 + n5 << endl;
    }

    return 0;
}

// my sol using rest
//int main() {
//	int N;
//	cin >> N;
//	if (3 <= N && N <= 5000) {
//		if (N % 5 == 3) cout << (N / 5) + 1 << endl;
//		else if (N % 5 == 0) cout << (N / 5) << endl;
//		else if (N % 5 == 1) cout << (N / 5) + 1 << endl;
//		else if (N % 5 == 4 && N != 4) cout << (N / 5) + 2 << endl;
//		else cout << -1 << endl;
//	}
//	else cout << -1 << endl;
//}