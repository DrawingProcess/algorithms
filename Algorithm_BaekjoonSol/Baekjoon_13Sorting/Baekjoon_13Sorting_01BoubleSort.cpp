#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
    int* num = new int [T];
	for (int i = 0; i < T; i++) {
		cin >> num[i];
	}
    for (int j = 0; j < T - 1; j++)
        for (int k = j + 1; k < T; k++) {
            if (num[j] > num[k]) {
                int temp = num[k];
                num[k] = num[j];
                num[j] = temp;
            }
        }

    for (int l = 0; l < T; l++) {
        if (l + 1 < T && num[l] == num[l + 1])
            continue;
        cout << num[l] << endl;
    }
}