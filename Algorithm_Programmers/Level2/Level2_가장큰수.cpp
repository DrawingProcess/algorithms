#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> result;
    for (int i = 0; i < numbers.size(); i++) {
        result.push_back(to_string(numbers[i]));
    }
    sort(result.begin(), result.end(), cmp);
    if (result[0] == "0") return "0";
    for (int i = 0; i < result.size(); i++) {
        answer += result[i];
    }
    return answer;
}