#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[51], brr[51];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> brr[j];
    }
    sort(arr, arr+n);
    sort(brr, brr+n, greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i] * brr[i];
    }
    cout << ans;
}