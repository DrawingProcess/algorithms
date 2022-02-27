#include <iostream>
#include <string>
using namespace std;

#include <map>

int main() {
	// map (based on Binary Search Tree) - Time complexity: O(logN)
	map<string, int> m;
	m["monkey"] = 4;
	m["banana"] = 3;
	m["harpsichord"] = 9;
	cout << m["banana"] << "\n"; // 3
	cout << m["banana2"] << "\n"; // 0 - generate default value
	// + unordered_map (based on Hash Table) - Time complexity: O(1)
}