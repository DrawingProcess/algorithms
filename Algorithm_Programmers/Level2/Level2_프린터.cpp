#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Num
{
    int idx;
    int prior;
};

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    vector<int> printer;
    vector<int> nums(9, 0);
    vector<Num> priority;

    for (int i = 0; i < priorities.size(); i++)
    {
        nums[9 - priorities[i]]++;

        Num temp;
        temp.idx = i;
        temp.prior = priorities[i];
        priority.push_back(temp);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            continue;
        else
        {
            // push pop 접근
            while (nums[i] != 0)
            {
                if (priority[0].prior == 9 - i)
                {
                    nums[i]--;
                    printer.push_back(priority[0].idx);
                    priority.erase(priority.begin()); // pop_front
                }
                else
                {
                    Num tmp;
                    tmp.idx = priority[0].idx;
                    tmp.prior = priority[0].prior;
                    priority.push_back(tmp);

                    priority.erase(priority.begin());
                }
            }
        }
    }
    for (int i = 0; i < printer.size(); i++)
    {
        if (printer[i] == location)
            answer = i + 1;
    }
    return answer;
}

int main()
{
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    cout << solution(priorities, location);
}