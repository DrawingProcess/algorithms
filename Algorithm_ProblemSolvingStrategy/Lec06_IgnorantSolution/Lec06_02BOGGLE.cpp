#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char board[5][5];
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

bool hasWord(int y, int x, const string& word) {
	if (x < 0 && x > 4 && y < 0 && y > 4) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction) {
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}
	return false;
}

int main() {
	int cases;
	cin >> cases;
	while (cases) {
		for (int i = 0; i < 5; i++) cin >> board[i];
		int wordNum;
		cin >> wordNum;
		while (wordNum--) {
			bool checkword = false;
			string word;
			cin >> word;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++)
					if (checkword = hasWord(j, i, word)) break;
				if (checkword) break;
			}
			if (checkword)
				cout << word << " YES\n";
			else
				cout << word << " NO\n";
		}
	}
}