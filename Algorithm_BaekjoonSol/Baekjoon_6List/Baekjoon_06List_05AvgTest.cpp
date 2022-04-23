#include <iostream>
using namespace std;
int main() {
	int index = 0; 
	double num, max = 0, sum = 0;
	cin >> num;
	double score[1000];

	for (int i = 0; i < num; i++) {
		cin >> score[i];
		if (score[i] > max) {
			max = score[i];
			index = i;
		}
	}
	for (int i = 0; i < num; i++){
		sum += score[i] / score[index] * 100.0;
	}
	cout << sum / num;
}