#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, result;
    int cnt;
    for (int i = 0; i < progresses.size(); i++) {
        cnt = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            cnt++;
        }
        result.push_back(cnt);
    }
    int before = result[0];
    cnt = 1;
    for (int i = 1; i < result.size(); i++) {
        if (result[i] <= before) cnt++;
        else {
            answer.push_back(cnt); 
            before = result[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}
int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };
    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}