#include <iostream>
#include <string>
#include <vector>

using namespace std;
int GCD(int n, int m) {
    if (n % m == 0) return m;
    else return GCD(m, n % m);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(GCD(n, m));
    answer.push_back(n*m / GCD(n, m));
    return answer;
}
int main() {
    int n = 3, m = 12;
    vector<int> result = solution(n, m);
    cout << result[0] << " " << result[1];
}