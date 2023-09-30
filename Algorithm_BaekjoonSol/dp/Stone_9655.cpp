#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 0;
    arr[3] = 1;
    arr[4] = 0;
    for (int i = 5; i <= n; i++)
    {
        if (arr[i-1] == 0 || arr[i-3] == 0)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    if (arr[n] == 1)
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
}