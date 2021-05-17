#include <iostream>
using namespace std;
int main() {
	int score;
	cin >> score;
	if (score >= 90 && score <= 100) cout << "A\n";
	else if (score >= 70 && score <= 89) cout << "B\n";
	else if (score >= 40 && score <= 69) cout << "C\n";
	else if (score >= 0 && score <= 39) cout << "D\n";
}