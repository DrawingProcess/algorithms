#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
bool compare(string a, string b) {
    if (a.at(N) != b.at(N)) {
        return a.at(N) < b.at(N);   //N�ε����� ���ڷ� ����
    }
    else {
        return a < b;   //���������� ����
    }
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    return answer;
}
int main() {
    vector<string> strings = { "sun", "bed", "car" };
    int n = 1;
    vector<string> result = solution(strings, n);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
}