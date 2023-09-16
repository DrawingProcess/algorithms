#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int> m;
    string str;
    int num = 0;
    while(getline(cin,str))
    {
        m[str]++;
        num++;
    }
    
    cout << fixed;
    cout.precision(4);
    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << ' ' << i->second *100 / (double)num << "\n";
    }
}