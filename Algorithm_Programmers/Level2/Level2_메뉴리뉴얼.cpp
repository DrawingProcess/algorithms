#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility> // for pair

using namespace std;

// i) solution
#include <map>
map<string, int> m;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void findAllCourse(string order, int size, string s, int index) {
    //��������
    if (s.length() == size) {
        map<string, int>::iterator iter;
        iter = m.find(s);
        //�ʿ� �ڽ��� �̹� �����ϴ� ��� -> ���� + 1
        if (iter != m.end()) {
            iter->second++;
        }
        //�ʿ� �ڽ��� �������� �ʴ� ��� -> �ʿ� ����
        else {
            m.insert(pair<string, int>(s, 1));
        }
        return;
    }
    for (int i = index; i < order.length(); i++) {
        findAllCourse(order, size, s + order[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    //�ڽ� ũ�� ��ŭ ��� �غ���
    for (int i = 0; i < course.size(); i++) {

        m.clear();

        for (int j = 0; j < orders.size(); j++) {

            //�޴� ����(ex. CBA -> ABC)
            sort(orders[j].begin(), orders[j].end());

            //�ֹ��� ���տ��� �ڽ� ������ŭ ���, ��� ���� ����� -> �ʿ� ����
            if (course[i] <= orders[j].length()) {
                findAllCourse(orders[j], course[i], "", 0);
            }
        }

        //map -> vector �ű��
        vector<pair<string, int>> v(m.begin(), m.end());

        //������� ���� ������ ���� ����
        sort(v.begin(), v.end(), cmp);

        if (!v.empty()) {
            //�ִ� ���� ũ�⸸ŭ ���信 ����
            int biggest = v[0].second;

            //�ּ� 2�� �̻� �մ����κ��� �ֹ��� �����̾�� �ϹǷ�
            if (biggest >= 2) {
                for (int i = 0; i < v.size(); i++) {
                    if (v[i].second == biggest) {
                        answer.push_back(v[i].first);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

// ii) My solution - failed
//bool cmp(pair<int, int> a, pair<int, int> b) {
//    return a.second() > b.second();
//}
//vector<string> solution(vector<string> orders, vector<int> course) {
//    vector<string> answer;
//    vector<pair<int, int>> manu(26);
//    for (int i = 0; i < 26; i++) {
//        manu[i].first = i + 1;
//        manu[i].second = 0;
//    }
//    for (int i = 0; i < orders.size(); i++) {
//        for (int j = 0; j < orders[i].size(); j++) {
//            manu[orders[i][j] - 'A'].second++;
//        }
//    }
//    sort(manu.begin(), manu.end(), cmp);
//    
//    sort(answer.begin(), answer.end());
//    return answer;
//}
int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    vector<string> result = solution(orders, course);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}