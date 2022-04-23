#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	for (int i = 1; i <= num * 2; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
					cout << "*";
				else cout << " ";
			}
			else
			{
				if (j % 2 == 0)
					cout << " ";
				else cout << "*";
			}
		}
		cout << endl;
	}
}