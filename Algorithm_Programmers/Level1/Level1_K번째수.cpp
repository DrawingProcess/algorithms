#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> ans;
    for (int i = 0; i < commands.size(); i++) {
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            ans.push_back(array[j]);
        }
        sort(ans.begin(), ans.end());
        answer.push_back(ans[commands[i][2] - 1]);
        ans.clear();
    }
    return answer;
}