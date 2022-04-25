#include <iostream>
using namespace std;
// expedient method
int main() {
	int A, B, V;
	cin >> A >> B >> V;
	cout << (V - B - 1) / (A - B) + 1;
}
// standard method
//int main() {
//	int A, B, V, num = 0, date = 1;
//	cin >> A >> B >> V;
//	while (true) {
//		num += A;
//		if (num == V) break;
//		num -= B;
//		date++;
//	}
//	cout << date;
//}