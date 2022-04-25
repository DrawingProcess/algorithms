#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T, H, W, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> H >> W >> N;
        N--;
        int X = N / H + 1;
        cout << N % H + 1;
        if (1 <= X && X <= 9)
            cout << "0" << X << "\n";
        else
            cout << X << "\n";
	}
}
// char type 0
//#include <iomanip>
//int main() {
//	int T, H, W, N;
//	cin >> T;
//	cout.fill('0');
//	for (int i = 0; i < T; ++i) {
//		cin >> H >> W >> N;
//		cout << N % H << setw(2) << N / H + 1;
//	}
//}