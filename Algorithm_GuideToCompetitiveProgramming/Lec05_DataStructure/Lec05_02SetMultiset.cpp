#include <iostream>
using namespace std;

#include <set>
#include <unordered_set>

int main() {
	// set (based on Binary Search Tree) - Time complexity: O(logN)
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1
	s.erase(3);
	cout << s.count(3) << "\n"; // 0
	s.insert(3);
	s.insert(3);
	s.insert(3);
	cout << s.count(3) << "\n"; // 1 - property of set
	s.erase(5);
	auto it = s.find(5);
	if (it == s.end())
		cout << "There is no element 5 in the set.\n";
	auto first = s.begin();
	auto last = s.end(); last--;
	cout << *first << " " << *last << "\n"; // Set is always aligned(Sorted).
	// + unordered_set (based on Hash Table) - Time complexity: O(1)

	// Multiset - A set that can have multiple equal values.
	multiset<int> ms;
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);
	cout << ms.count(5) << "\n"; // 4
	ms.erase(ms.find(5));
	cout << ms.count(5) << "\n"; // 3
	ms.erase(5);
	cout << ms.count(5) << "\n"; // 0
	// + unordered_multiset
}