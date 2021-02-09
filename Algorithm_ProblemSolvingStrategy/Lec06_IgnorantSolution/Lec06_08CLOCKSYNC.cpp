#include <iostream>
#include <vector>
using namespace std;

// Problem: https://algospot.com/judge/problem/read/CLOCKSYNC
/* input
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6
*/

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//linked[i][j]=1 i번 스위치와 j번 시계가 연결되어 있다
//linked[i][j]=0 i번 스위치와 j번 시계가 연결되어 있지 않다
int linked[SWITCHES][CLOCKS] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};
//모든 시계가 12시를 가리키고 있는지 확인
bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < CLOCKS; i++)
        if (clocks[i] != 12)
            return false;
    return true;
}
//SWITCHES번 스위치를 누른다
void push(vector<int>& clocks, int swtch) {
    for (int clock = 0; clock < CLOCKS; clock++)
        if (linked[swtch][clock] == 1) {
            clocks[clock] += 3;
            if (clocks[clock] == 15) //3, 6, 9, 12까지 이므로
                clocks[clock] = 3;
        }
}
//clocks:현재 시계들의 상태
//swtch:이번에 누를 스위치의 번호
//가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환
//만약 불가능하다면 INF 이상의 큰 수를 반환
int solve(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES)
        return areAligned(clocks) ? 0 : INF;
    //이 스위치를 0번 누르는 경우부터 세번 누르는 경우까지를 모두 시도(12시면 0번, 3시면 3번)
    int result = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        result = min(result, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    //push(clocks, swtch)가 네번 호출되었으니 clocks는 원래와 같은 상태
    return result;
}

int main(void) {
    vector<int> clocks(CLOCKS);
    int cases;
    cin >> cases;
    if (cases < 0 || cases > 30)
        exit(-1);
    while (cases--) {
        for (int i = 0; i < CLOCKS; i++)
            cin >> clocks[i];
        int result = solve(clocks, 0);
        if (result == INF)
            cout << -1 << endl;
        else
            cout << result << endl;
    }
    return 0;
}