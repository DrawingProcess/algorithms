#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // i)
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    // ii)
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' || \
            (new_id[i] >= 48 && new_id[i] <= 57) || (new_id[i] >= 97 && new_id[i] <= 122))
            continue;
        else {
            new_id.erase(i, 1);
            i--;
        }
    }
    // iii)
    for (int i = 0; i < new_id.size()-1; i++) {
        if (new_id[i] == '.' && new_id[i + 1] == '.') {
            new_id.erase(i, 1);
            i--;
        }
    }
    // iV)
    while (new_id[0] == '.')
        new_id.erase(0, 1);
    while (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();
    // V)
    if (new_id.size() == 0)
        new_id.append("a");
    // Vi)
    if (new_id.size() >= 16)
        new_id = new_id.substr(0, 15);
    // iV) for testcase 5
    while (new_id[0] == '.')
        new_id.erase(0, 1);
    while (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();
    // Vii)
    if (new_id.size() <= 2)
        while(new_id.size() != 3)
            new_id.push_back(new_id[new_id.size()-1]);
    swap(new_id, answer);
    return answer;
}
int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    cout << solution(new_id);
}