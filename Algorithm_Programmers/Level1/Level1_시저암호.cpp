#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { answer.push_back(s[i]); continue; }
        else if ('A' <= s[i] && s[i] <= 'Z' && s[i] + n > 'Z') s[i] -= 26;
        else if ('a' <= s[i] && s[i] <= 'z' && s[i] + n > 'z') s[i] -= 26;
        answer.push_back(s[i] + n);
    }
    return answer;
}
int main() {
    string s = "a B z";
    int n = 4;
    cout << solution(s, n);
}