#include <iostream>
using namespace std;
int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int tri = n1 < n2 ? n1 : n2;
	tri = tri < n3 ? tri : n3;
	cout << tri;
}