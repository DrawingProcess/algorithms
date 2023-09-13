#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<pair<int, int>> deq; 
    int n, num;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        deq.push_back({i, num});
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << deq.front().first << " ";
        num = deq.front().second;
        deq.pop_front();

        if (num >=0)
        {
            for (int j = 1; j < num; j++)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        }
        else
        {
            for (int j = 1; j < abs(num)+1; j++)
            {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
}