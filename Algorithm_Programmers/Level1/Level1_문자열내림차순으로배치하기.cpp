#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(char a, char b) {
    return a > b;
}
string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), compare);
    answer = s;
    return answer;
}
int main() {
    string s = "Zbcdefg";
    cout << solution(s);
}