#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int N;
	long long int count = 0;
	stack <int> s;
	cin >> N;
	for (int i = 0; i < N; i++)	{
		int x;
		cin >> x;
		while (!s.empty() && s.top() <= x) {// 스택이 비어있지 않고 자신의 키가 top 이상일 때 계속 반복
			s.pop(); //스택의 맨 윗값을 제거	
		}
		s.push(x);
		if (s.size() >= 1) count += s.size() - 1; // 헤어스타일을 볼 수 있는 소의 마리수 추가 (count += s.top을 볼 수 있는 소들)
	}

	cout << count;
}

//#include <iostream>
//#include <stack>
//using namespace std;
//int main() {
//	stack<int> tmp, stk;
//	int num, n, sum = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		tmp.push(num);
//	}
//	for (int i = 0; i < n; i++) {
//		stk.push(tmp.top());
//		tmp.pop();
//	}
//	for (int i = 0; i < n; i++) {
//		int cnt = 0;
//		num = stk.top();
//		stk.pop();
//		tmp = stk;
//		for (int j = i; j < n; j++) {
//			if (!tmp.empty() && num > tmp.top()) {
//				cnt++;
//				tmp.pop();
//			}
//			else break;
//		}
//		sum += cnt;
//	}
//	cout << sum;
//}