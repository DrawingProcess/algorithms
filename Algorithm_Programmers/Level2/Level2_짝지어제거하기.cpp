#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ii) using vector: O(n)
int solution(string s)
{
    int answer = 0;
    vector<char> chr;
    for (int i = 0; i < s.size(); i++) {
        if (chr.empty() || chr.back() != s[i]) chr.push_back(s[i]);
        else if (chr.back() == s[i]) chr.pop_back();
    }
    if (chr.empty()) return 1;
    return 0;
}
// ii) 시간초과: O(n^2)
int solution(string s)
{
    int answer = 0;
    string before = s;
    while (true) {
        before = s;
        for (int i = 0; i < s.size(); i++) {
            if (s.begin() + i + 1 != s.end() && s[i] == s[i + 1]) {
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);
                i--;
            }
        }
        if (s == before) return false;
        else if (s == "") return true;
    }
}
int main() {
    string s = "cdcd";
    cout << solution(s);
}