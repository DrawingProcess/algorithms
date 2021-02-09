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
//linked[i][j]=1 i�� ����ġ�� j�� �ð谡 ����Ǿ� �ִ�
//linked[i][j]=0 i�� ����ġ�� j�� �ð谡 ����Ǿ� ���� �ʴ�
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
//��� �ð谡 12�ø� ����Ű�� �ִ��� Ȯ��
bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < CLOCKS; i++)
        if (clocks[i] != 12)
            return false;
    return true;
}
//SWITCHES�� ����ġ�� ������
void push(vector<int>& clocks, int swtch) {
    for (int clock = 0; clock < CLOCKS; clock++)
        if (linked[swtch][clock] == 1) {
            clocks[clock] += 3;
            if (clocks[clock] == 15) //3, 6, 9, 12���� �̹Ƿ�
                clocks[clock] = 3;
        }
}
//clocks:���� �ð���� ����
//swtch:�̹��� ���� ����ġ�� ��ȣ
//�� �־��� ��, ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ
//���� �Ұ����ϴٸ� INF �̻��� ū ���� ��ȯ
int solve(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES)
        return areAligned(clocks) ? 0 : INF;
    //�� ����ġ�� 0�� ������ ������ ���� ������ �������� ��� �õ�(12�ø� 0��, 3�ø� 3��)
    int result = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        result = min(result, cnt + solve(clocks, swtch + 1));
        push(clocks, swtch);
    }
    //push(clocks, swtch)�� �׹� ȣ��Ǿ����� clocks�� ������ ���� ����
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