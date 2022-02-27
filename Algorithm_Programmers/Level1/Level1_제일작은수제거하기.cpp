#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min_i = -1, minimum = 987654321;
    for (int i = 0; i < arr.size(); i++) {
        if (minimum > arr[i]) {
            minimum = arr[i];
            min_i = i;
        }
    }
    arr.erase(arr.begin() + min_i);
    if (!arr.size()) arr.push_back(-1);
    answer = arr;
    return answer;
}
int main() {
    vector<int> arr = { 4,3,2,1 };
    vector<int> result = solution(arr);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}s