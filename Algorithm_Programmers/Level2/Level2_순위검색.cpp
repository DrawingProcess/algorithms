#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> lang, career, part, soul, score, temp;
    string buf;
    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        while (ss >> buf) {
            temp.push_back(buf);
        }
        lang.push_back(temp[0]);
        career.push_back(temp[1]);
        part.push_back(temp[2]);
        soul.push_back(temp[3]);
        score.push_back(temp[4]);
        temp.clear();
    }
    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        while (ss >> buf) {
            temp.push_back(buf);
        }
        int cnt = 0;
        for (int i = 0; i < lang.size(); i++) {
            if ((lang[i] == temp[0] || temp[0] == "-") && \
                (career[i] == temp[2] || temp[2] == "-") && \
                (part[i] == temp[4] || temp[4] == "-") && \
                (soul[i] == temp[6] || temp[6] == "-") && \
                stoi(score[i]) >= stoi(temp[7])) cnt++;
        }
        answer.push_back(cnt);
        temp.clear();
    }
    return answer;
}
int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> result = solution(info, query);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}