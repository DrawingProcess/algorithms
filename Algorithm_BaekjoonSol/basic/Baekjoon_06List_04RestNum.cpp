#include <iostream>
using namespace std;

int main() {
    int num, sum = 0, remainderArr[42] = { 0, };
    for (int i = 0; i < 10; i++) {
        cin >> num;
        if (!remainderArr[num % 42]++) // 인덱스마다 value가 0일 경우만 sum에 1씩 더하게 됨.
            sum++;
    }
    cout << sum;
}