#include <iostream>
using namespace std;

int cnt;
int prepre;

void stair(int lev, int prev, int prepre, int n) {
    if (lev > n) return;
    if (lev == n) {
        cnt++;
        return;
    }
    if (prev != 3 && prepre != 3) stair(lev + 3, 3, prev, n);
    stair(lev + 1, 1, prev, n);
    stair(lev + 2, 2, prev, n);
}

int main() {
    int num;
    cnt = 0;
    cin >> num;
    stair(0, 0, 0, num);
    cout << cnt;
}