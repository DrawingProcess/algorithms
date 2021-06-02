#include <iostream>
using namespace std;
int main() {
	int out, in, total = 0, max = 0;
	for (int i = 0; i < 10; i++) {
		cin >> out >> in;
		total = total - out + in;
		max = max < total ? total : max;
	}
	cout << max;
}