#include <iostream>
using namespace std;
int main() {
	char iter;
	cin >> iter;
	// using for
	for (int i = 0; i <= iter - 'a'; i++) {
		char chr(i + 'a');
		cout << chr << " ";
	}
	// using while
	//while(iter != 0) {
	//	cout << iter-1 << "\n";
	//	iter--;
	//}
}