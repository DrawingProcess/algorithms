// Merge Sort
// Time Complexity: O(N*logN)
# include <iostream>
using namespace std;

const int number = 8;

void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}
void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[number];
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}

int main() {
    int data[number] = { 5,2,4,7,1,3,2,6 }, i;
    for (i = 0; i < number; i++)
        cout << data[i] << " ";
    cout << "\n";
    mergeSort(data, 0, number - 1);
    for (i = 0; i < number; i++)
        cout << data[i] << " ";
}