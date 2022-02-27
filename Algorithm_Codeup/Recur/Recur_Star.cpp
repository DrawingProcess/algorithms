#include <iostream>
using namespace std;
void g(int k)
{
	if (k <= 0) return;
	g(k - 1);
	cout << "*";
}

void f(int k)
{
	if (k <= 0) return;
	f(k - 1);
	g(k);
	cout << "\n";
}
int main() {
	int num;
	cin >> num;
	f(num);
}