#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	//��ü���� ���
	int sum = brown + red;
	//���̴� �ּ�3���� ����
	for (int height = 3; ; height++) {
		//������ ���̷� ���������� �������� 0�϶���
		if (!(sum % height)) {
			//���� ���̷� ������ ���α��̰� �ȴ�.
			int weight = sum / height;
			//�׵θ��� �����̹Ƿ� 2�پ� ���� ���
			//���̿��� 2�������� ���α��̿��� 2���� ���� ���Ѱ��� ������������ ���ٸ� ���� ���� ���̸� ã�����̴�.
			if (((height - 2) * (weight - 2)) == red) {
				answer.push_back(weight);
				answer.push_back(height);
				break;
			}
		}
	}
	return answer;
}

int main() {
	int brown = 10;
	int yellow = 2;
	vector<int> result = solution(brown, yellow);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}