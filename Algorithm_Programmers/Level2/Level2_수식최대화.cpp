#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, location;
    string n = "";

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            num.push_back(stoi(n));
            n = "";
            if (find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.push_back(expression[i]);
            location.push_back(expression[i]);
        }
        else
            n += expression[i];
    }

    num.push_back(stoi(n));
    sort(exp.begin(), exp.end());

    do
    {
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = location;

        for (int i = 0; i < exp.size(); i++)
        {
            for (int j = 0; j < tmp_loc.size(); j++)
            {
                if (exp[i] == tmp_loc[j])
                {
                    if (tmp_loc[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if (tmp_loc[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if (tmp_loc[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while (next_permutation(exp.begin(), exp.end()));

    return answer;
}
//// 문제를 잘못이해함..
//long long solution(string expression) {
//    long long answer = 0, result = 0;
//    vector<int> num;
//    string oper;
//    int operIndex = 0;
//    for (int i = 0; i < expression.size(); i++) {
//        if (i == expression.size() - 1) num.push_back(stoi(expression.substr(operIndex, i - operIndex + 1)));
//        if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
//            num.push_back(stoi(expression.substr(operIndex, i - operIndex)));
//            oper.push_back(expression[i]);
//            operIndex = i + 1;
//        }
//    }
//    sort(oper.begin(), oper.end());
//    do {
//        result = num[0];
//        for (int i = 0; i < oper.size(); i++) {
//            if (oper[i] == '+') result += num[i+1];
//            else if (oper[i] == '-') result -= num[i + 1];
//            else if (oper[i] == '*') result *= num[i + 1];
//        }
//        answer = max(answer, abs(result));
//    } while (next_permutation(oper.begin(), oper.end()));
//    return answer;
//}
int main() {
    string expression = "100-200*300-500+20";
    //result: 60420
    cout << solution(expression);
}