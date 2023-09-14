#include <iostream>
#include <queue>

int main()
{
    int n, k, num;
    std::cin >> n >> k;
    std::cout << "<";

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while(!q.empty())
    {
        for (int i = 0; i < k-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        if (q.size() == 1)
        {
            std::cout << q.front() << ">";
            q.pop();
        }
        else
        {
            std::cout << q.front() << ", ";
            q.pop();
        }
    }
}