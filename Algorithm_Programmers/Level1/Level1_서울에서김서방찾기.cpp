#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int result = -1;
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") result = i;
    }
    answer = "�輭���� " + to_string(result) + "�� �ִ�";
    return answer;
}
int main() {
    vector<string> s = { "Jane", "Kim" };
    cout << solution(s);
}