#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int coin[11];
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        if (k >= coin[i])
        {
            cnt += k / coin[i];
            k %= coin[i];
        }
    }
    cout << cnt;
}