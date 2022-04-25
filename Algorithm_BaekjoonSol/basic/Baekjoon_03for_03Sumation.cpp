#include <iostream>
using namespace std;
int main(){
	int n, sum = 0;
	cin >> n;
	if (1 <= n && n <= 10000) {
		for (int i = 0; i <= n; ++i) {
			sum += i;
		}
		cout << sum;
	}
	return 0;
}