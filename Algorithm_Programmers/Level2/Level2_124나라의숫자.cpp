#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int remainder = -1;

    while (n != 0) {
        remainder = n % 3;
        n /= 3;
        //³ª´©¾î ¶³¾îÁú °æ¿ì ¸òÀ» 1»©ÁØ´Ù.
        if (remainder == 0) { answer += "4"; n--; }
        else if (remainder == 1) { answer += "1"; }
        else if (remainder == 2) { answer += "2"; }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main() {
    int n = 7;
    cout << solution(n);
}