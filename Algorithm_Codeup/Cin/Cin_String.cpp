#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int i = stoi(str.substr(0, str.find('.')));
	int f = stoi(str.substr(str.find('.') + 1));
	cout << i << "\n" << f;
	return 0;
}