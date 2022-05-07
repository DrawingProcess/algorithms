#include <iostream>
using namespace std;
int main(){
    int dice[7] = {0,};
    int a, b, c, max = 0;
    cin >> a >> b >> c;
    dice[a]++;
    dice[b]++;
    dice[c]++;

    for (int i = 1; i < 7; i++){
        if (dice[i] == 3){
            cout << 10000 + i * 1000;
            break;
        }
        else if (dice[i] == 2){
            cout << 1000 + i * 100;
            break;
        }
        else if (dice[i] == 1){
            max = i;
        }
        if (i == 6)
            cout << max * 100;
    }
}