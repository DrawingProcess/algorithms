#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int value = n / 2;
    for (int i = 0; i < value; i++) {
        answer += "¼ö¹Ú";
    }
    if (n % 2 != 0) answer += "¼ö";
    return answer;
}