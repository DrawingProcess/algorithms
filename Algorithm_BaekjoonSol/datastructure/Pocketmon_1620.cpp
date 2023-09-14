#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    
    map<int, string> m;
    map<string, int> ms;
    string str;
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        m[i] = str;
        ms[str] = i;
    }
    for (int i = 1; i <= f; i++)
    {
        cin >> str;
        if ('0' <= str[0] && str[0] <= '9')
        {
            int num = stoi(str);
            cout << m[num] << "\n";
        }
        else
        {
            cout << ms[str] << "\n";
        }
    }

}