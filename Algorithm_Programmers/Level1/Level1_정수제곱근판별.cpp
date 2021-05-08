#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) answer = (i + 1) * (i + 1);
    }
    if (!answer) answer = -1;
    return answer;
}
int main() {

}