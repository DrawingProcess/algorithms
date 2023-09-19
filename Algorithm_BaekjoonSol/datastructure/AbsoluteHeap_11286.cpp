#include <iostream>
#include <queue>
using namespace std;

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, comp> pq;
    int n = 0, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
}