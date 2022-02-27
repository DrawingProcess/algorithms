#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int total = 0;
    int cnt = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            cnt++;
            continue;
        }
        if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) {
            total++;
        }
    }
    // 다 못맞췄을 때
    if (total + cnt == 0) {
        answer.push_back(6);
        answer.push_back(6);
    }
    else {
        answer.push_back(6 - total - cnt + 1);
        if (total == 0)
            answer.push_back(6);
        else
            answer.push_back(6 - total + 1);
    }
    return answer;
}
int main() {
    vector<int> lottos = { 0,0,0,0,0,0 };
    vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
    // result: [3,5]
    vector<int> result = solution(lottos, win_nums);

    for (int i = 0; i < 2; i++)
        cout << result[i] << " ";
}