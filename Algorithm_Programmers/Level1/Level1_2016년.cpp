#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> monthDay = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int cnt = 0;
    for (int i = 0; i < a - 1; i++) {
        cnt += monthDay[i];
    }
    cnt += b + 5 - 1; // DAY + 1/1: FRI
    cnt = cnt % 7;
    if (cnt == 0) answer = "SUN";
    else if (cnt == 1) answer = "MON";
    else if (cnt == 2) answer = "TUE";
    else if (cnt == 3) answer = "WED";
    else if (cnt == 4) answer = "THU";
    else if (cnt == 5) answer = "FRI";
    else if (cnt == 6) answer = "SAT";
    return answer;
}
int main() {
    int a = 1, b = 1;
    cout << solution(a, b);
}