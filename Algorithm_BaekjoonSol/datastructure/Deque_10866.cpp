#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    int n;
    cin >> n;

    deque<int> deq;
    for (int i = 0; i < n; i++)
    {
        int num;
        string str;
        cin >> str;
        if (str == "push_back")
        {
            cin >> num;
            deq.push_back(num);
        }
        else if (str == "push_front")
        {
            cin >> num;
            deq.push_front(num);
        }
        else if (str == "pop_front")
        {
            if (deq.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << deq.front() << "\n";
            deq.pop_front();
        }
        else if (str == "pop_back")
        {
            if (deq.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << deq.back() << "\n";
            deq.pop_back();
        }
        else if (str == "front")
        {
            if (deq.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << deq.front() << "\n";
        }
        else if (str == "back")
        {
            if (deq.empty())
            {
                cout << "-1\n";
                continue;
            }
            cout << deq.back() << "\n";
        }
        else if (str == "size")
        {
            cout << deq.size() << "\n";
        }
        else if (str == "empty")
        {
            cout << deq.empty() << "\n";
        }
    }
}