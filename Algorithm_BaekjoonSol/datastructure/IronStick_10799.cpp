#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    stack<char> s;
    cin >> str;

    int total = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' and str[i - 1] == '(')
        {
            s.pop();
            total += s.size();
        }
        else
        {
            total++;
            s.pop();
        }
    }
    cout << total << endl;
}