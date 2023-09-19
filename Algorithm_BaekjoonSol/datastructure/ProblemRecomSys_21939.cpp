#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

struct comp
{
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<pair<int, int>, comp> ms;
    map<int, int> mm;
    int n, num, level;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num >> level;
        ms.insert({level, num});
        mm[num] = level;
    }
    // for (auto i = ms.begin(); i != ms.end(); i++)
    // {
    //     cout << i->first << " " << i->second << "\n";
    // }

    string str;
    cin >> n;
    while(n--)
    {
        cin >> str;
        if (str == "add")
        {
            cin >> num >> level;
            ms.insert(make_pair(level, num));
            mm[num] = level;
        }
        else if (str == "recommend")
        {
            cin >> num;
            if (num == -1)
            {
                cout << ms.begin()->second << "\n";
            }
            else if (num == 1)
            {
                auto iter = ms.end();
                iter--;
                cout << iter->second << "\n";
            }
        }
        else if(str == "solved")
        {
            cin >> num;
            ms.erase({mm[num], num});
            // for (auto iter = ms.begin(); iter != ms.end(); iter++)
            // {
            //     if (iter->second == num)
            //     {
            //         ms.erase(iter);
            //         break;
            //     }
            // }
        }
    }
}