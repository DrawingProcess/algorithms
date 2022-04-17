#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//시간복잡도 n
int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());
    int lt = 0;
    int rt = people.size() - 1;
    while (lt <= rt)
    {
        int sum = people[lt] + people[rt];
        if (lt != rt-- && sum <= limit)
            lt++;
        answer++;
    }
    return answer;
}

// // 시간복잡도 n^2
// int solution(vector<int> people, int limit)
// {
//     int answer = 0;
//     vector<bool> ride(people.size(), false);
//     sort(people.begin(), people.end(), greater<int>());
//     for (int i = 0; i < people.size(); i++)
//     {
//         if (ride[i])
//             continue;
//         for (int j = i + 1; j < people.size(); j++)
//         {
//             if (!ride[j] && people[i] + people[j] <= limit)
//             {
//                 ride[i] = 1, ride[j] = 1;
//                 answer++;
//                 break;
//             }
//         }
//         if (!ride[i]){
//             ride[i] = 1;
//             answer++;
//         }
//     }
//     return answer;
// }
int main()
{
    vector<int> people = {70, 50, 80, 50, 90, 40};
    int limit = 240;
    cout << solution(people, limit);
}