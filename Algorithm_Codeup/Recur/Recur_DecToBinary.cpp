#include <iostream>
using namespace std;

void binary(int num) {
	if (!num) {
		return;
	}
	binary(num / 2);
	cout << num % 2;
}
int main() {
	int num;
	cin >> num;
	if (num) binary(num);
	else cout << 0;
}
//#include <iostream>
//#include <bitset>
//using namespace std;
//int main() {
//	int c;
//	cin >> c;
//	cout << bitset<8>(c) << '\n';
//	return 0;
//}