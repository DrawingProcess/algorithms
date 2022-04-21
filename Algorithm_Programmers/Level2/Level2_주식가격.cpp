#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            answer[i]++;
            if (prices[i] > prices[j])
                break;
        }
    }
    return answer;
}

int main()
{
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);

    for (int i = 0; i < prices.size(); i++)
    {
        cout << answer[i] << " ";
    }
}