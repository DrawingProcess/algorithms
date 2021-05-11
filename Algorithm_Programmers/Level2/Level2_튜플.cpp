#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<vector<int>> result_s;
    vector<int> answer, result;
    int start = 0, end = 0;
    bool flag = false, check[1000001] = { false, };
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') {
            flag = true;
            start = i+1;
        }
        else if (flag && s[i] == ',') {
            result.push_back(stoi(s.substr(start, i - start)));
            start = i + 1;
        }
        else if (s[i] == '}') {
            result.push_back(stoi(s.substr(start, i - start)));
            result_s.push_back(result);
            result.clear();
            start = i + 1;
            flag = false;
        }
    }
    sort(result_s.begin(), result_s.end(), cmp);
    for (int i = 0; i < result_s.size(); i++) {
        for (int j = 0; j < result_s[i].size(); j++) {
            if (!check[result_s[i][j]]) {
                check[result_s[i][j]] = true;
                answer.push_back(result_s[i][j]);
            }
        }
    }
    return answer;
}
int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> result = solution(s);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}