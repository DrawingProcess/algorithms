#include <iostream>
#include <string>
#include <vector>
#include <cmath> // for sqrt

using namespace std;

// ii) sqrt사용
long long solution(long long n) {
    long long answer = 0;
    long long sqr = sqrt(n);
    if (sqr * sqr == n) answer = (sqr + 1) * (sqr + 1);
    if (!answer) answer = -1;
    return answer;
}

// ii) for문 사용
long long solution(long long n) {
    long long answer = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) answer = (i + 1) * (i + 1);
    }
    if (!answer) answer = -1;
    return answer;
}