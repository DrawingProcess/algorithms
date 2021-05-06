#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    int three = 1;
    while (n - three >= 0) {
        three *= 3;
    }
    three /= 3;
    int value = 0, modulo = 0;
    string threeS = "";
    int threeR = three;
    while (three != 0) {
        value = n / three;
        modulo = n % three;
        threeS.append(to_string(value));
        n = modulo;
        three /= 3;
    }
    reverse(threeS.begin(), threeS.end());
    int cnt = 1;
    for (int i = threeS.size() - 1; i >= 0; i--) {
        answer += int(threeS[i] - '0') * cnt;
        cnt *= 3;
    }
    return answer;
}
int main() {
    int n = 45;
    cout << solution(n);
}