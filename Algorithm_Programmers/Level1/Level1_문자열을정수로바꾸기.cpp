#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool plus = true;
    if (s[0] == '-') { plus = false; s.erase(0, 1); }
    else if (s[0] == '+') { plus = true; s.erase(0, 1); }
    if (!plus) answer = -stoi(s);
    else if (plus) answer = stoi(s);
    return answer;
}
int main() {
    string s = "-1234";
    cout << solution(s);
}