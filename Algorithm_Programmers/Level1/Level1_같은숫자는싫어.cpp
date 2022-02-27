#include <vector>
#include <iostream>

using namespace std;

//vector<int> solution(vector<int> arr)
//{
//    vector<int> answer;
//    for (int i = 0; i < arr.size(); i++) {
//        answer.push_back(arr[i]);
//        while (i != arr.size() - 1 && arr[i] == arr[i + 1]) {
//            arr.erase(arr.begin() + i);
//        }
//    }
//    return answer;
//}

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int exist_L = 0;
    int exist[11] = { -1, };
    for (int i = 0; i < arr.size(); i++) {
        if (exist[exist_L] == arr[i]) continue;
        answer.push_back(arr[i]);
        exist[exist_L + 1] = arr[i];
        exist_L++;
    }
    return answer;
}
int main() {
    vector<int> arr = { 1,1,1,2,2,2,3 };
    vector<int> result = solution(arr);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}