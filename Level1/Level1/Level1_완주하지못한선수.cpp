#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// solution1_score10
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool* have_p = new bool[participant.size()];
    bool* have_c = new bool[participant.size()];
    for (int i = 0; i < participant.size(); i++) {
        have_p[i] = false;
        have_c[i] = false;
    }
    for (int i = 0; i < completion.size(); i++) {
        for (int j = 0; j < participant.size(); j++) {
            if (!have_c[i] && completion[i] == participant[j]) {
                have_c[i] = true, have_p[j] = true;
            }
        }
    }
    for (int i = 0; i < participant.size(); i++) {
        if (!have_p[i]) {
            answer = participant[i];
        }
    }
    delete[] have_c;
    delete[] have_p;
    return answer;
}

// solution1_score100
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++) {
        if (completion[i] != participant[i]) {
            if (completion[i] == participant[i + 1]) {
                answer = participant[i];
                return answer;
            }
            else if (completion[i + 1] == participant[i]) {
                answer = completion[i];
                return answer;
            }
        }
    }
    if (answer == "")
        answer = participant[participant.size() - 1];
    return answer;
}