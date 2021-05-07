#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int numP = 0, numY = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P') numP++;
        else if (s[i] == 'y' || s[i] == 'Y') numY++;
    }
    if (numP != numY) answer = false;
    return answer;
}
int main() {
    string s = "pPoooyY";
    cout << solution(s);
}