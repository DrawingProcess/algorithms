#include <iostream>
using namespace std;
int main() {
	const int max = 2000;
	int price, result1 = max, result2 = max;
	for (int i = 0; i < 5; i++) {
		cin >> price;
		if (100 <= price && max >= price) {
			if (i < 3) // 햄버거 값
				price < result1 ? result1 = price : result1;
			else // 음료값
				price < result2 ? result2 = price : result2;
		}
	}
	cout << result1 + result2 - 50;
}