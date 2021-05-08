#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> // pow

using namespace std;
// i) string으로 변환
long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);
    return answer;
}

// ii) vector로 변환
bool compare(int a, int b) {
    return a > b;
}
long long solution(long long n) {
    long long answer = 0;
    vector<int> result;
    while (n != 0) {
        result.push_back(n % 10);
        n /= 10;
    }
    sort(result.begin(), result.end(), compare);
    int i = 0;
    while(result.size()) {
        if (i == 0) { answer += result.back(); result.pop_back(); }
        else { answer += result.back() * pow(10, i); result.pop_back(); }
        i++;
    }
    return answer;
}
int main() {
    int n = 12345;
    cout << solution(n);
}