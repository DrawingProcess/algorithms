#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        multiset<int> ms;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            char chr;
            cin >> chr >> num;
            if (chr == 'I')
            {
                ms.insert(num);
            }
            else if(chr == 'D')
            {
                if (!ms.empty() && num == 1)
                {
                    auto iter = ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else if (!ms.empty() && num == -1)
                {
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            auto iter = ms.end();
            iter--;
            cout << *iter << " " << *ms.begin() << "\n";
        }
    }
}