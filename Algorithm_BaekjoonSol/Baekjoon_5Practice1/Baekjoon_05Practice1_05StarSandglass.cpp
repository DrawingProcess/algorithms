#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) { // 2n+1 reverse Pyramid 
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int k = num - 2*(i-2); k > 0; k--) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = 1; i < num; i++) { // 2n+1 Pyramid (i = 0)
		for (int j = num - i - 1; j > 0; j--) {
			cout << ' ';
		}
		for (int k = 0; k < 2*i+1; k++) {
			cout << '*';
		}
		cout << '\n';
	}
}
/* solution
#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	int cnt = n-1;
	for (int i = 1; i < 2 * n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
		{
			if (j >= n - cnt && j <= n + cnt)
			{
				cout << "*";
			}
			else if (j < n - cnt)
			{
				cout << " ";
			}
		}
		if (i < n) cnt--;
		else cnt++;
		cout << "\n";
	}
}
*/