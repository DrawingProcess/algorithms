#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[i] = make_pair(end, start);
    }
    sort(arr, arr+n);
    int cnt = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        if (end <= arr[i].second)
        {
            end = arr[i].first;
            cnt++;
        }
    }
    cout << cnt;
}