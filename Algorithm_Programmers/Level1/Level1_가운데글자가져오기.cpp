#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.size() % 2 == 1) answer = s[s.size() - s.size() / 2 - 1];
    else answer = s.substr(s.size() - s.size() / 2 - 1, 2);
    return answer;
}
int main() {
    string s = "abcde";
    // return: "c"
    cout << solution(s);
}