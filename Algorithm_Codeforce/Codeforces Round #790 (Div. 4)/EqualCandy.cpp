#include <iostream>
using namespace std;
int main(){
    int T, num, number;
    cin >> T;
    for (int i = 0; i < T; i++){
        int sum = 0, min = 10000000;
        cin >> num;
        for (int j = 0; j < num; j++){
            cin >> number;
            sum += number;
            min = min < number ? min : number;
        }
        sum -= min * num;
        cout << sum << "\n";
    }
}