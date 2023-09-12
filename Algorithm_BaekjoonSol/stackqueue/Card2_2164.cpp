#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    if (q.size() == 1)
    {
        std::cout << q.front();
        q.pop();
    }
    while(!q.empty())
    {
        q.pop();
        if (q.size() == 1)
        {
            std::cout << q.front();
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    
}