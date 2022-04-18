#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int count0 = 0, i = 0, j = 0, result = 0;
    while (true)
    {
        if (i == 6 || j == 6)
            break;

        if (lottos[i] == 0)
        {
            count0++;
            i++;
            continue;
        }

        if (lottos[i] == win_nums[j])
        {
            result++;
            i++;
            j++;
        }
        else if (lottos[i] > win_nums[j])
        {
            j++;
        }
        else if (lottos[i] < win_nums[j])
        {
            i++;
        }
    }
    vector<int> answer;
    if (count0 == 0 && result == 0)
    {
        answer.push_back(6);
        answer.push_back(6);
    }
    else
    {
        answer.push_back(6 - (result + count0) + 1);
        if (result == 0)
            answer.push_back(6);
        else
            answer.push_back(6 - result + 1);
    }

    return answer;
}
int main()
{
    vector<int> lottos = {44, 1, 0, 0, 31, 25};
    vector<int> win_nums = {31, 10, 45, 1, 6, 19};
    vector<int> answer = solution(lottos, win_nums);
    cout << answer[0] << " " << answer[1];
}