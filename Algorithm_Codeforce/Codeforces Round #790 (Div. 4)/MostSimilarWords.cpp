#include <iostream>
#include <string>
using namespace std;
int main(){
    string s[50];
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int n, m, min = 10000;
        cin >> n >> m;
        for (int j = 0; j < n; j++){
            cin >> s[j];
        }
        for (int j = 0; j < n; j++){
            for (int k = j+1; k < n; k++)
            {
                int sum = 0;
                for (int h = 0; h < m; h++)
                {
                    sum += abs(s[j][h] - s[k][h]);
                }
                min = min < sum ? min : sum;
            }
        }
        cout << min << "\n";
    }
}