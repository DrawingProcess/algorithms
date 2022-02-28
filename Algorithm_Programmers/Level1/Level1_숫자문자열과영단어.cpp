#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ('0' <= s[i] && '9' >= s[i])
        {
            answer += int(s[i] - '0');
        }
        else
        {
            if (s[i] == 'z')
            {
                i += 3;
            }
            else if (s[i] == 'o')
            {
                answer += 1;
                i += 2;
            }
            else if (s[i] == 't')
            {
                if (s[i + 1] == 'w')
                {
                    answer += 2;
                    i += 2;
                }
                else if (s[i + 1] == 'h')
                {
                    answer += 3;
                    i += 4;
                }
            }
            else if (s[i] == 'f')
            {
                if (s[i + 1] == 'o')
                {
                    answer += 4;
                    i += 3;
                }
                else if (s[i + 1] == 'i')
                {
                    answer += 5;
                    i += 3;
                }
            }
            else if (s[i] == 's')
            {
                if (s[i + 1] == 'i')
                {
                    answer += 6;
                    i += 2;
                }
                else if (s[i + 1] == 'e')
                {
                    answer += 7;
                    i += 4;
                }
            }
            else if (s[i] == 'e')
            {
                answer += 8;
                i += 4;
            }
            else if (s[i] == 'n')
            {
                answer += 9;
                i += 3;
            }
        }
        answer *= 10;
    }
    answer /= 10;
    return answer;
}

int main() {
    string s = "one4seveneight";
    cout << solution(s);
}

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <regex>

// using namespace std;

// vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

// int solution(string s)
// {
//     int answer = 0;
//     regex r;
//     for (int i = 0; i < numbers.size(); i++)
//     {
//         r = numbers[i];
//         s = regex_replace(s, r, to_string(i));
//     }
//     answer = stoi(s);
//     return answer;
// }