#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool isRight(char c, int diff, int num) {
    if (c == '=') {
        return diff == num;
    }
    else if (c == '>') {
        return diff > num;
    }
    else if (c == '<') {
        return diff < num;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool flag = true;
        for (string text : data) {
            char ff = text[0];
            char sf = text[2];
            char comp = text[3];
            int num = text[4] - '0';
            int diff = friends.find(ff) - friends.find(sf);
            int dis = abs(diff) - 1;

            if (isRight(comp, dis, num)) continue;
            flag = false;
            break;
        }
        if (flag) answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}
int main() {
    int n = 2;
    vector<string> data = { "N~F=0", "R~T>2" };
    // result: 3648
    cout << solution(n, data);
}