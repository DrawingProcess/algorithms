#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer, answerT;
    string temp, temp1, temp2;
    for (int i = 0; i < arr1.size(); i++) {
        temp1 = bitset<16>(arr1[i]).to_string();
        temp2 = bitset<16>(arr2[i]).to_string();
        temp1 = temp1.substr(16 - n, 16);
        temp2 = temp2.substr(16 - n, 16);
        for (int j = 0; j < temp1.size(); j++) {
            if (temp1[j] == '1' || temp2[j] == '1') {
                temp.push_back('1');
            }
            else {
                temp.push_back('0');
            }
        }
        answerT.push_back(temp);
        temp.clear();
    }
    for (int i = 0; i < answerT.size(); i++) {
        for (int j = 0; j < answerT[0].size(); j++) {
            if (answerT[i][j] == '1') {
                temp.push_back('#');
            }
            else {
                temp.push_back(' ');
            }
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}
int main() {
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };
    vector<string> result = solution(n, arr1, arr2);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
}