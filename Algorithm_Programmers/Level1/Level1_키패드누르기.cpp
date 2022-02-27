#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int locaL = 10, locaR = 12;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            locaL = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            locaR = numbers[i];
        }
        else { // 2580
            if (locaL == 0)
                locaL = 11;
            if (locaR == 0)
                locaR = 11;
            if (numbers[i] == 0)
                numbers[i] = 11;
            // 몇층차이나지?
            int number = numbers[i];
            int cntL = 0, cntR = 0;
            int locaLL = locaL, locaRR = locaR;
            while (locaLL > 3) {
                locaLL -= 3;
                cntL++;
            }
            while (locaRR > 3) {
                locaRR -= 3;
                cntR++;
            }
            int numberF = number;
            while (numberF > 3) {
                numberF -= 3;
                number %= 3;
                cntL--;
                cntR--;
            }
            cntL = abs(cntL);
            cntR = abs(cntR);
            // 몇자리차이나지?
            int left = abs(locaLL - number);
            int right = abs(locaRR - number);
            cntL += left;
            cntR += right;
            if (cntL > cntR) {
                answer += "R";
                locaR = numbers[i];
            }
            else if (cntL < cntR) {
                answer += "L";
                locaL = numbers[i];
            }
            else { // cntL = cntR
                if (hand == "left") {
                    answer += "L";
                    locaL = numbers[i];
                }
                else if (hand == "right"){
                    answer += "R";
                    locaR = numbers[i];
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    string hand = "right";
    // result = "LLRLLRLLRL"
    cout << solution(numbers, hand);
}