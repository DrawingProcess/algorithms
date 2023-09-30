#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[5001];
    arr[0] = 0;
    arr[1] = -1;
    arr[2] = -1;
    arr[3] = 1;
    arr[4] = -1;
    arr[5] = 1;
    for (int i = 5; i <= n; i++)
    {
        if (arr[i-5] >= 0 && arr[i-3] >= 0)
        {
            arr[i] = min(arr[i-5], arr[i-3]) + 1;
        }
        else if (arr[i-5] >= 0)
        {
            arr[i] = arr[i-5] + 1;
        }
        else if (arr[i-3] >= 0)
        {
            arr[i] = arr[i-3] + 1;
        }
        else
        {
            arr[i] = -1;
        }
    }
    cout << arr[n];
}