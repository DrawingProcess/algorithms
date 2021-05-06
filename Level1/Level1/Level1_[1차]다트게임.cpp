#include <iostream>
#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score = 0;
    int score_b = 0;
    for (int i = 0; i < dartResult.size(); i += 2) {
        if (dartResult[i + 1] == '0') { score = 10; i++; }
        else score = int(dartResult[i] - '0');
        if (dartResult[i + 1] == 'D') score *= score;
        else if (dartResult[i + 1] == 'T') score *= score * score;
        if (dartResult[i + 2] == '#') {
            score = -score;
            answer += score;
            i++;
        }
        else if (dartResult[i + 2] == '*') {
            score = score * 2;
            answer += score + score_b;
            i++;
        }
        else answer += score;
        score_b = score;
    }
    return answer;
}
int main() {
    string dartResult = "1S*2D*3T*";
    cout << solution(dartResult);
}