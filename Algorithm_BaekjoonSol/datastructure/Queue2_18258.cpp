#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int N, x;
string s;
queue<int> q;



int main()
{
	// 빠른 입출력을 위해서 적어줍니다.
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		if (s == "push")
		{
			cin >> x;
			q.push(x);
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';

		}
		else if (s == "size")
		{
			cout << q.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (s == "front")
		{
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else // s == "back"
		{
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
	}

}

// #include <iostream>
// #include <vector>
// #include <string>

// class Que
// {
// private:
//     std::vector<int> nums;
//     int size_;
// public:
//     Que()
//     {
//         size_ = 0;
//     }
//     void push(int num)
//     {
//         nums.push_back(num);
//         size_++;
//     }
//     int pop()
//     {
//         int num = this->front();
//         if (this->size() > 0) {
//             nums.erase(nums.begin());
//             size_--;
//         }
//         return num;
//     }
//     int size()
//     {
//         return size_;
//     }
//     bool empty()
//     {
//         if (!size_)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     int front()
//     {
//         if(this->empty()) return -1;
//         return nums[0];
//     }
//     int back()
//     {
//         if(this->empty()) return -1;
//         return nums[this->size() - 1];
//     }
// };


// int main()
// {
// 	// 빠른 입출력을 위해서 적어줍니다.
// 	std::cin.tie(NULL);
// 	std::cin.sync_with_stdio(false);

//     Que queue;

//     std::string str;
//     int n, tmp;
//     std::cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> str;
//         if (str == "push")
//         {
//             std::cin >> tmp;
//             queue.push(tmp);
//         }
//         else if (str == "pop")
//         {
//             std::cout << queue.pop() << "\n";
//         }
//         else if (str == "size")
//         {
//             std::cout << queue.size() << "\n";
//         }
//         else if (str == "empty")
//         {
//             std::cout << queue.empty() << "\n";
//         }
//         else if (str == "front")
//         {
//             std::cout << queue.front() << "\n";
//         }
//         else if (str == "back")
//         {
//             std::cout << queue.back() << "\n";
//         }
//     }

// }