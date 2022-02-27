#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// using vector(�����迭 ���� ������ �� ����.)
// pair(Ŭ������ ������ �ʿ䰡 ����.)

// 3 various
bool compare(pair<string, pair<int, int>> a,
			 pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}
int main() {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("���ѿ�", make_pair(90, 1996)));
	v.push_back(pair<string, pair<int, int>>("������", make_pair(97, 1993)));
	v.push_back(pair<string, pair<int, int>>("������", make_pair(95, 1993)));
	v.push_back(pair<string, pair<int, int>>("������", make_pair(90, 1992)));
	v.push_back(pair<string, pair<int, int>>("�̻��", make_pair(88, 1990)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " ";
}

// 2 various
//int main() {
//	vector<pair<int, string>> v;
//	v.push_back(pair<int, string>(90, "���ѿ�"));
//	v.push_back(pair<int, string>(85, "������"));
//	v.push_back(pair<int, string>(82, "������"));
//	v.push_back(pair<int, string>(98, "������"));
//	v.push_back(pair<int, string>(72, "�̻��"));
//
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++)
//		cout << v[i].second << " ";
//}