#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0, count = 0;
    sort(numbers.begin(), numbers.end());
    for (const int &num : numbers)
    {
        while (num != count)
        {
            answer += count;
            count++;
        }
        if (num == count)
        {
            count++;
        }
    }
    while (count != 10)
    {
        answer += count;
        count++;
    }
    return answer;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 0};
    cout << solution(nums);
}

// //solution
// int solution(vector<int> numbers)
// {
//     int answer = 45;
//     for (int i = 0; i < numbers.size(); i++)
//         answer -= numbers[i];
//     return answer;
// }