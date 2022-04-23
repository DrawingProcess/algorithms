#include <iostream>
using namespace std;
int main() {
	int score, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> score;
		if (0 <= score && 100 >= score && score%5 == 0) {
			if (score < 40)
				sum += 40;
			else
				sum += score;
		}
	}
	cout << sum / 5;
}