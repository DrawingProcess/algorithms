#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> check[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> temp;
    string buf;
    int lang, career, part, soul;
    for (int i = 0; i < info.size(); i++) {
        stringstream ss(info[i]);
        while (ss >> buf) {
            temp.push_back(buf);
        }
        if (temp[0] == "cpp") lang = 0;
        else if (temp[0] == "java") lang = 1;
        else lang = 2;
        if (temp[1] == "backend") career = 0;
        else career = 1;
        if (temp[2] == "junior") part = 0;
        else part = 1;
        if (temp[3] == "chicken") soul = 0;
        else soul = 1;
        check[lang][career][part][soul].push_back(stoi(temp[4]));
        temp.clear();
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    // 2. 체크 벡터 chkVec[3][2][2][2] 인원들의 점수를 정렬
                    sort(check[i][j][k][l].begin(), check[i][j][k][l].end());
                }
            }
        }
    }
    int score;
    for (int i = 0; i < query.size(); i++) {
        stringstream ss(query[i]);
        while (ss >> buf) {
            temp.push_back(buf);
        }
        if (temp[0] == "-") lang = -1;
        else if (temp[0] == "cpp") lang = 0;
        else if (temp[0] == "java") lang = 1;
        else lang = 2;
        if (temp[2] == "-") career = -1;
        else if (temp[2] == "backend") career = 0;
        else career = 1;
        if (temp[4] == "-") part = -1;
        else if (temp[4] == "junior") part = 0;
        else part = 1;
        if (temp[6] == "-") soul = -1;
        else if (temp[6] == "chicken") soul = 0;
        else soul = 1;
        if (temp[7] == "-") score = -1; 
        else score = stoi(temp[7]);
        temp.clear();

        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (lang != -1 && lang != i) continue;
            for (int j = 0; j < 2; j++) {
                if (career != -1 && career != j) continue;
                for (int k = 0; k < 2; k++) {
                    if (part != -1 && part != k) continue;
                    for (int l = 0; l < 2; l++) {
                        if (soul != -1 && soul != l) continue;
                        // 3. lower_bound() 함수로 점수구간 이진 탐색, 쿼리 조건의 점수위치 iterator 찾아 갯수 계수
                        auto low = lower_bound(check[i][j][k][l].begin(), check[i][j][k][l].end(), score);
                        for (; low != check[i][j][k][l].end(); ++low) cnt++;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//    vector<string> lang, career, part, soul, score, temp;
//    string buf;
//    for (int i = 0; i < info.size(); i++) {
//        stringstream ss(info[i]);
//        while (ss >> buf) {
//            temp.push_back(buf);
//        }
//        lang.push_back(temp[0]);
//        career.push_back(temp[1]);
//        part.push_back(temp[2]);
//        soul.push_back(temp[3]);
//        score.push_back(temp[4]);
//        temp.clear();
//    }
//    for (int i = 0; i < query.size(); i++) {
//        stringstream ss(query[i]);
//        while (ss >> buf) {
//            temp.push_back(buf);
//        }
//        int cnt = 0;
//        for (int i = 0; i < lang.size(); i++) {
//            if ((lang[i] == temp[0] || temp[0] == "-") && \
//                (career[i] == temp[2] || temp[2] == "-") && \
//                (part[i] == temp[4] || temp[4] == "-") && \
//                (soul[i] == temp[6] || temp[6] == "-") && \
//                stoi(score[i]) >= stoi(temp[7])) cnt++;
//        }
//        answer.push_back(cnt);
//        temp.clear();
//    }
//    return answer;
//}
int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> result = solution(info, query);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}