#include <iostream>
using namespace std;

bool equidistantCheck(int num) {
	int eachNum[3] = {}, j = 0, origin = num;
	if (num < 100)
		return true;
	while (origin != 0) {
		if (num == 1000)
			return false;
		eachNum[2 - j] += origin % 10;
		origin /= 10;
		j++;
	}
	if (eachNum[2] - eachNum[1] == eachNum[1] - eachNum[0]) {
		return true;
	}
	return false;
}
int main() {
	int limit, equidistantNum = 0;
	cin >> limit;
	for (int i = 1; i <= limit; i++) {
		if (equidistantCheck(i))
			equidistantNum++;
	}
	cout << equidistantNum;
}