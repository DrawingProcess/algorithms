#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>

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

	//���Ͽ� ���������� �� ����
	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) temp_arr[k] = arr[i++];
		else temp_arr[k] = arr[j++];
		k++;
	}

	//���� ������ ����
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

	//�ӽ� ����� �迭�� ����� ���� ���� �迭�� �־���
	for (int t = start; t <= end; ++t) {
		arr[t] = temp_arr[t];
	}
}
void mergeSort(int* arr, int start, int end) {
	//ũ�Ⱑ 1 �ϴ� ���� ȣ��, 1���� ���� �ɰ�
	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle + 1, end);
		//�ٽ� ����
		merge(arr, start, middle, end);
	}
}

// algorithm sort for descending order
bool comp(int a, int b) {
	return a > b;
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

	// algorithm sort
	int arr3[] = { 2, 4, 6, 7, 5, 1, 3, 8, 9 };
	sort(arr3, arr3 + n, comp);
	for (int i = 0; i < n; i++)
		cout << arr3[i] << " ";
	cout << "\n";

	vector<int> arr4 = { 2, 4, 6, 7, 5, 1, 3, 8, 9 };
	sort(arr4.begin(), arr4.end());
	for (int i = 0; i < n; i++)
		cout << arr4[i] << " ";
	cout << "\n";

}