#include <iostream>
using namespace std;

#include <vector>
#include <deque>
#include <stack>
#include <queue>

int main() {
	// vector (Implement Stack using vector library)
	vector<int> v = { 2, 5, 7 };
	v.push_back(3);
	v.push_back(9);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << "\n";

	// deque (Implement Doubly linked list using vector library)
	deque<int> d;
	d.push_back(5);
	d.push_back(3);
	d.push_front(1);
	d.pop_front();
	d.pop_back();

	// stack
	stack<int> s;
	s.push(2);
	cout << s.top() << "\n";
	s.pop();

	// queue
	queue<int> q;
	q.push(2);
	q.push(5);
	cout << q.front() << "\n";
	cout << q.back() << "\n";
	q.pop();
}