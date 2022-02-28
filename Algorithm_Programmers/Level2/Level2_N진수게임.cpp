#include <iostream>
#include <string>
#include <vector>

using namespace std;

char List[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string trans(int num, int n)
{
    string result = "";
    while (num / n != 0)
    {
        string Temp = result;
        result = List[num % n];
        result += Temp;
        num /= n;
    }
    string Temp = result;
    result = List[num % n];
    result += Temp;
    return result;
}

string solution(int n, int t, int m, int p)
// n: 진법, t: 미리 구할 숫자의 갯수, m: 게임에 참가하는 인원, p: 순서
{
    string result = "", answer = "";
    int cnt = 0;
    for (int i = 0; i < t * m; i++)
    {
        result += trans(i, n);
    }
    for (int i = p - 1; i < result.length(), cnt < t; i += m)
    {
        answer += result[i];
        cnt++;
    }
    return answer;
}

int main(){
    cout << solution(2, 4, 2, 1);
}