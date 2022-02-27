#include <iostream>
using namespace std;

int main() {
	// time complexity: O(n^3)
	int sum, best = 0, n = 8, arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
	for (int a = 0; a < n; a++) {
		for (int b = a; b < n; b++) {
			sum = 0;
			for (int k = a; k <= b; k++) {
				sum += arr[k];
			}
			best = max(best, sum);
		}
	}
	cout << best << "\n";

	// time complexity: O(n^2)
	best = 0;
	for (int a = 0; a < n; a++) {
		sum = 0;
		for (int b = a; b < n; b++) {
			sum += arr[b];
			best = max(best, sum);
		}
	}
	cout << best << "\n";

	// time complexity: O(n)
	best = 0, sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(arr[k], sum + arr[k]);
		best = max(best, sum);
	}
	cout << best << "\n";
}