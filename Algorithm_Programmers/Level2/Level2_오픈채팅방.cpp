#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, state;
    map<string, string> user; // userid, name을 함께 저장

    for (int i = 0; i < record.size(); i++)
    {
        string str[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;
        
        // 띄어쓰기를 기준으로 slicing 
        while (ss >> token)
            str[index++] = token;

        if (str[0] == "Enter")
        {
            state.push_back("님이 들어왔습니다.");
            answer.push_back(str[1]);
            user[str[1]] = str[2];
        }
        else if (str[0] == "Leave")
        {
            state.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
        }
        else
            user[str[1]] = str[2];
    }

    for (int i = 0; i < answer.size(); i++)
        answer[i] = user[answer[i]] + state[i];

    return answer;
}

// //ii) only pass test case
//vector<string> solution(vector<string> record) {
//    vector<string> answer;
//    vector<string> result, id;
//    vector<int> re, index;
//    string option, userid, name;
//    for (int i = 0; i < record.size(); i++) {
//        for (int j = 0; j < record[i].size(); j++) {
//            if (record[i][j] == ' ') { re.push_back(j); }
//        }
//        re.push_back(record[i].size() - 1);
//        option = record[i].substr(0, re[0]);
//        if (re.size() == 2) {
//            userid = record[i].substr(re[0] + 1, re[1] - re[0] + 1);
//        }
//        else if (re.size() == 3) {
//            userid = record[i].substr(re[0] + 1, re[1] - re[0] - 1);
//            name = record[i].substr(re[1] + 1, re[2] - re[1] + 1);
//        }
//
//        auto it_i = find(id.begin(), id.end(), userid);
//        while (it_i != id.end()) {
//            // it_i의 인덱스: it_i - id.begin()
//            index.push_back(it_i - id.begin());
//            it_i = find(it_i+1, id.end(), userid);
//        }
//        if (option == "Enter") {
//            result.push_back(name);
//            id.push_back(userid);
//            for (int j = 0; j < index.size(); j++) {
//                answer[index[j]] = answer[index[j]].substr(result[index[j]].size(), answer.size() - result[index[j]].size()); //e.g. "님이 ~"
//                answer[index[j]] = name + answer[index[j]];
//            }
//            answer.push_back(name + "님이 들어왔습니다.");
//        }
//        else if (option == "Leave") {
//            //id.erase(id.begin() + index[0]);
//            //result.erase(result.begin() + index[0]);
//            name = result[index[0]];
//            result.push_back(name);
//            id.push_back(userid);
//            answer.push_back(name + "님이 나갔습니다.");
//        }
//        else if (option == "Change") {
//            for (int j = 0; j < index.size(); j++) {
//                //result[index[j]] = name;
//                answer[index[j]] = answer[index[j]].substr(result[index[j]].size(), answer.size() - result[index[j]].size());
//                answer[index[j]] = name + answer[index[j]];
//            }
//        }
//        //for (int j = 0; j < result.size(); j++)
//        //    cout << result[j] << " ";
//        //cout << "\n";
//        //for (int j = 0; j < answer.size(); j++)
//        //    cout << answer[j] << " ";
//        //cout << "\n";
//
//        re.clear();
//        index.clear();
//        option = "", userid = "", name = "";
//    }
//    return answer;
//}
int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan", "Leave uid1234 Prodo" };
    vector<string> result = solution(record);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}