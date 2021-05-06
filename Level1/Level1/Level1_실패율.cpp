#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
    else if (a.second > b.second)
        return true;
    else
        return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> FailRate;
    double remain = stages.size();
    double failRate;
    int* stay = new int[N + 2];
    for (int i = 0; i <= N; i++)
        stay[i] = 0;
    for (int i = 0; i < stages.size(); i++) {
        stay[stages[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (stay[i] == 0)
            failRate = 0;
        else
            failRate = stay[i] / remain;
        FailRate.push_back({ i, failRate });
        remain -= stay[i];
    }
    sort(FailRate.begin(), FailRate.end(), compare);
    for (int i = 0; i < FailRate.size(); i++) {
        answer.push_back(FailRate[i].first);
    }
    delete [] stay;
    return answer;
}
int main() {
    int N = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    vector<int> result = solution(N, stages);
    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
}