// Quick Sort
// Time Complexity: O(N*logN)
# include <iostream>
using namespace std;

int n, cnt, quick[10000001];

void quickSort(int i, int j)
{
	if (i >= j) return;
	int pivot = quick[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--;
		if (left <= right)
		{
			swap(quick[left], quick[right]);
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> quick[i];
	// 8 
	// 5 2 4 7 1 3 2 6 

	quickSort(0, n - 1);

	for (int i = 0; i < n; i++) // Ãâ·Â
		cout << quick[i] << " ";
}