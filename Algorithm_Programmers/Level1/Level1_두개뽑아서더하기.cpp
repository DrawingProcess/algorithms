#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool exist[201] = {false,};
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i == j) continue;
            if (exist[numbers[i] + numbers[j]]) continue;
            answer.push_back(numbers[i] + numbers[j]);
            exist[numbers[i] + numbers[j]] = true;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main() {
    vector<int> numbers = { 2,1,3,4,1 };
    vector<int> result = solution(numbers);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}