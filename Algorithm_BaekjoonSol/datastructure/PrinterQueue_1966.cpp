#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Prior{
    int idx;
    int prior;
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums(10);
        queue<Prior> q;
        
        int m, index, num;
        cin >> m >> index;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            Prior pri;
            pri.idx = j;
            pri.prior = num;
            q.push(pri);
            nums[num]++;
        }

        bool flag = false;
        num = 1;
        for (int j = 9; j >= 1; j--)
        {
            if (nums[j] == 0) continue;
            if (flag) break;
            while(nums[j])
            {
                if(q.front().prior == j)
                {
                    if (q.front().idx == index)
                    {
                        cout << num << "\n";
                        flag = true;
                        break;
                    }
                    q.pop();
                    nums[j]--;
                    num++;
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
        }
    }
}