#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { cnt = 0; continue; }
        if (cnt % 2 == 0 && islower(s[i])){ // È¦¼ö
            s[i] -= 32;
        }
        else if (cnt % 2 == 1 && isupper(s[i])) { // Â¦¼ö
            s[i] += 32;
        }
        cnt++;
    }
    answer = s;
    return answer;
}
int main() {
    string s = " try hello world ";
    cout << solution(s);
}