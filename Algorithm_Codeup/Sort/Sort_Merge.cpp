#include <iostream>
using namespace std;
#define MAXSORT 10
int sorted[MAXSORT];

void merge(int* data, int start, int mid, int end) {
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end) {
		if (data[i] <= data[j]) {
			sorted[k] = data[i];
			i++;
		}
		else {
			sorted[k] = data[j];
			j++;
		}
		k++;
	}
	if (i < mid) {
		for (int t = i; t <= mid; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	else {
		for (int t = j; t <= end; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	for (int t = 0; t < end; t++) {
		data[t] = sorted[t];
	}
}
void merge_sort(int* data, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(data, start, mid);
		merge_sort(data, mid+1, end);
		merge(data, start, mid, end);
	}
}