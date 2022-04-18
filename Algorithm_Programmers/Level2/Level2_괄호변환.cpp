#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p)
{
    string answer = "";
    // 1.
    if (p.size()==0)
        return answer;

    // 2.
    int i = 0, total = 0, positive = 0;
    while (true)
    {
        if (i != 0 && total == 0)
            break;
        if (p[i] == '('){
            total++;
        }
        else if (p[i] == ')'){
            total--;
        }
        if (total > 0)
            positive = 1; // 올바른 문자열
        i++;
    }
    string u = p.substr(0, i), v = p.substr(i);

    // 3
    if (positive > 0)
        answer = u + solution(v);
    // 4
    else {
        string temp = '(' + solution(v) + ')';
        u = u.substr(1, u.size()-2);
        for (int i = 0; i < u.size(); i++){
            if (u[i] == '(')
                u[i] = ')';
            else if (u[i] == ')')
                u[i] = '(';
        }
        answer = temp + u;
    }
    return answer;
}
int main(){
    string p = "()))((()";
    cout << solution(p);
}