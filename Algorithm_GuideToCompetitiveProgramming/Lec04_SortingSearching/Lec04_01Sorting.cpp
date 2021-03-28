#include <iostream>
using namespace std;

// bubble sort
void bubbleSort(int n, int* arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// merge sort
int temp_arr[9];

void merge(int* arr, int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;

	//비교하여 데이터정렬 및 삽입
	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) temp_arr[k] = arr[i++];
		else temp_arr[k] = arr[j++];
		k++;
	}

	//남은 데이터 삽입
	if (i > middle) {
		for (int t = j; t <= end; ++t) {
			temp_arr[k] = arr[t];
			++k;
		}
	}
	else {
		for (int t = i; t <= middle; ++t) {
			temp_arr[k] = arr[t];
			++k;
		}
	}

	//임시 저장용 배열에 저장된 값을 원래 배열에 넣어줌
	for (int t = start; t <= end; ++t) {
		arr[t] = temp_arr[t];
	}
}
void mergeSort(int* arr, int start, int end) {
	//크기가 1 일대 까지 호출, 1단위 까지 쪼갬
	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		//다시 병합
		merge(arr, start, middle, end);
	}
}

int main() {
	// bubble sort
	int arr[] = { 2, 4, 6, 7, 5, 1, 3, 8, 9 };
	int n = 9;
	bubbleSort(n, arr);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	// merge sort
	int arr2[] = { 2, 4, 6, 7, 5, 1, 3, 8, 9 };
	mergeSort(arr2, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << arr2[i] << " ";
	cout << "\n";
}