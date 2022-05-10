#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> s;
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += int(s[j]);
        }
        for (int j = 0; j < 3; j++)
        {
            sum -= int(s[j+3]);
        }
        if (sum == 0){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}