#include <iostream>
#include <string>
#include <vector>

// 주의할 점: reserve와 lost가 같은 사람일 수 있다.(자신한태 할당) + n=5, lost:[1,2,3], reserve:[2,3,4]

using namespace std;

// i) 복잡 -> pass, reser을 없앨 수는 없을까?(ii 참고)
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> reser(n, false);
    for (int i = 0; i < n - lost.size(); i++) {
        answer++;
    }
    for (int i = 0; i < reserve.size(); i++) {
        reser[reserve[i] - 1] = true;
    }
    // n=5, lost:[1,2,3], reserve:[2,3,4] -> answer:4
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i]) {
                reser[reserve[j] - 1] = false;
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                j--;
                i--;
                answer++;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        bool pass = false;
        for (int j = 0; j < reserve.size(); j++) {
            if (!pass && reser[reserve[j] - 1] && lost[i] - 1 == reserve[j]) {
                reser[reserve[j] - 1] = false;
                answer++;
                pass = true;
            }
            else if (!pass && reser[reserve[j] - 1] && lost[i] + 1 == reserve[j]) {
                reser[reserve[j] - 1] = false;
                answer++;
                pass = true;
            }
        }
    }
    return answer;
}
// ii) lost도 지우는 방법을 사용하여 pass, reser 없애기
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> reser(n, false);
    for (int i = 0; i < n - lost.size(); i++) {
        answer++;
    }
    // n=5, lost:[1,2,3], reserve:[2,3,4] -> answer:4
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                j--;
                i--;
                answer++;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] - 1 == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                j--;
                i--;
                answer++;
            }
            else if (lost[i] + 1 == reserve[j]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
                j--;
                i--;
                answer++;
            }
        }
    }
    return answer;
}


int main() {
    vector<int> lost = { 1, 2, 3 };
    vector<int> reserve = { 2, 3, 4 };
    int n = 5;
    cout << solution(n, lost, reserve);
}