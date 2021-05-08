#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    if (num < 0) num = -num; // int의 범위이므로
    if (num % 2 == 0) answer = "Even";
    else if (num % 2 == 1) answer = "Odd";
    return answer;
}