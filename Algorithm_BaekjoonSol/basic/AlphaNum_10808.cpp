#include <iostream>
#include <string>
using namespace std;
int main()
{
    int alpha[26];
    fill(alpha, alpha + 26, 0);

    string S;
    cin >> S;
    for (int i = 0; i < S.length(); i++)
    {
        alpha[S[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alpha[i] << " ";
    }

    return 0;
}