#include <iostream>
using namespace std;

#include <queue>

int main() {
	// priority_queue (based on Heap)
	priority_queue<int> q;
	q.push(5);
	q.push(7);
	q.push(9);
	q.push(3);
	q.push(4);
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}

	// Max heap
	// priority_queue< int, vector<int>, less<int> > pq;
	// Min heap
	// priority_queue< int, vector<int>, greater<int> > pq;
}