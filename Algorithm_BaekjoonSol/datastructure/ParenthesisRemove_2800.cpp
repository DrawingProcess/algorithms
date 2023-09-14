#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
    stack<int> s;
    queue<int> q;
    string str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else if (str[i] == ')')
        {
            q.push(i);
        }
    }
}