#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int rope[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> rope[i];
    }
    sort(rope, rope+n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, rope[n-i] * i);
    }
    cout << ans;
}