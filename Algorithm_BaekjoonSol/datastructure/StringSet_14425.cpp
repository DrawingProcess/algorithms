#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    set<string> s;
    string str;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        s.insert(str);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if(s.find(str) != s.end())
        {
            cnt++;
        } 
    }
    cout << cnt;
}