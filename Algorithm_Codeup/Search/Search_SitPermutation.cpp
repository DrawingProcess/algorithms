#include <iostream>
using namespace std;

int cnt = 0;
void f(int n, int bit) {
    if (!n) {
        cnt++;
        return;
    }
    f(n - 1, 1);
    if (bit) f(n - 1, 0);
}
int main() {
    int n;
    cin >> n;
    f(n, 1);
    cout << cnt;
    return 0;
}