#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int origin = x;
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
    if (origin % sum == 0) answer = true;
    return answer;
}