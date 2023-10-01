#include <iostream>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (n+1)/2 << "\n";
        multiset<int> s;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            s.insert(num);
            if (i % 2 == 0)
            {
                auto iter = s.begin();
                for (int j = 0; j < i/2; j++)
                {
                    iter++;
                }
                cout << *iter << " ";
            }
        }
    }
}