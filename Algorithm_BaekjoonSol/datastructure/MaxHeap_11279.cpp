#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    vector<int> result;
    int n, num;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num != 0)
        {
            pq.push(num);
        }
        else
        {
            if(pq.empty())
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(pq.top());
                pq.pop();
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}