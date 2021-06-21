#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        int cnt = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) cnt++;
        }
        cnt++;
        if (cnt % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}
int main() {
    int left = 13, right = 17;
    cout << solution(left, right);
}