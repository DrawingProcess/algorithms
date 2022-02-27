#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        vector<char> key;
        string s;
        cin >> s;
        bool answer = true;
        for (int i = 0; i < s.size(); i++)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                key.push_back(s[i]);
            }
            else
            {
                if (find(key.begin(), key.end(), s[i] - 'A' + 'a') == key.end())
                {
                    answer = false;
                    break;
                }
            }
        }
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
        s.clear();
        key.clear();
    }
    return 0;
}