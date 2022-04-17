#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    for (int i = 0, index = -1; i < number.size() - k; i++)
    {
        char max = 0;
        for (int j = index + 1; j <= k+i; j++)
        {
            if (max < number[j]){
                index = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}

int main(){
    string number = "1924";
    int k = 2;
    cout << solution(number, k);
}