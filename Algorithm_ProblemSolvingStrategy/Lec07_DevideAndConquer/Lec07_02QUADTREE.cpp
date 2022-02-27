#include<iostream>
#include<string>

using namespace std;

void quadTree(const string& word) {
	if (word.size() == 1) {
		cout << word;
		return;
	}
	int idx[4] = { 0 };
	int count = 1;
	int cnt = 0;
	int idxCnt = 0;
	for (int i = 1; i < word.size(); i++) {
		cnt++;
		if (count == cnt) {
			idx[idxCnt] = i;
			idxCnt++;
			count = 1;
			cnt = 0;
		}
		if (word[i] == 'x') count += 4;
	}
	cout << "x";
	quadTree(word.substr(idx[2], idx[3] - idx[2]));
	quadTree(word.substr(idx[3]));
	quadTree(word.substr(idx[0], idx[1] - idx[0]));
	quadTree(word.substr(idx[1], idx[2] - idx[1]));
}

int main() {
	int testCase;
	cin >> testCase;
	for (int tc = 0; tc < testCase; tc++) {
		string word;
		cin >> word;
		quadTree(word);
		cout << endl;
	}
	return 0;
}

/*
// solved Decompressed
#include <iostream>

#include <string>

using namespace std;



//���� Ʈ�� ������ ������ �ذ��ϴ� ���� ���� �˰���

string reverse(string::iterator &it)

{

		char head = *it;

		++it;

		//���� ���: 1�� Ȥ�� 2�� ������ ���

		if (head == 'b' || head == 'w')

			   return string(1, head);

		//�켱 ������ ĭ�� �����´�(4���ҵ� ĭ��)

		string upperLeft = reverse(it); //4��и�

		string upperRight = reverse(it); //1��и�

		string lowerLeft = reverse(it); //2��и�

		string lowerRight = reverse(it); //3��и�



		//���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�(�̷��� ��μ� ������ ������ ���̴�)

		return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;

}



int main(void)

{
		int test_case;
		string picture;
		cin >> test_case;
		if (test_case < 0 || test_case>50)
			   exit(-1);
		for (int i = 0; i < test_case; i++) {
			   cin >> picture;
			   if (picture.size() > 1000)
					   exit(-1);
			   string::iterator it = picture.begin();
			   cout << reverse(it) << endl;
		}
		return 0;
}



// solved Reverse
#include <iostream>
#include <string>
using namespace std;

string Reverse(string::iterator& iter) {
	char head = *iter;
	iter++;
	if (head == 'w' || head == 'b') return string(1, head);
	string upperLeft = Reverse(iter);
	string upperRight = Reverse(iter);
	string lowLeft = Reverse(iter);
	string lowRight = Reverse(iter);
	return string("x") + lowLeft + lowRight + upperLeft + upperRight;
}

int main(void) {
	int cases;
	cin >> cases;
	string tree;
	while (cases--) {
		cin >> tree;
		string::iterator iter = tree.begin();
		cout << Reverse(iter) << endl;
	}
}
*/