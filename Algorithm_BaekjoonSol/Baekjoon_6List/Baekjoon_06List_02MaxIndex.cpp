#include <iostream>
using namespace std;

int main() {
	int num[100], max = 0, Index = 0, i = 0;
	for (int i = 0; i < 9; i++){
		cin >> num[i];
		if (i >= 1) {
			max = max >= num[i] ? max : num[i];
			if (max == num[i])
				Index = i;
		}
		else
			max = num[i];
	}
	cout << max << '\n' << Index+1;
}