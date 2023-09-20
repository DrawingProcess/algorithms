#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n, num = 0;
    string str;
    cin >> str >> n;

    for (int i = 0; i < str.size(); i++)
    {
        int tmp = str[str.size() - i - 1];
        if ('A' <= tmp && 'Z' >= tmp)
        {
            tmp = 10 + tmp - 'A';
        }
        else
        {
            tmp = tmp - '0';
        }
        num += tmp * (int)pow(n, i);
    }
    cout << num;
}