#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if (num < 0) num = -num; // int�� �����̹Ƿ�
    if (num % 2 == 0) answer = "Even";
    else if (num % 2 == 1) answer = "Odd";
    return answer;
}