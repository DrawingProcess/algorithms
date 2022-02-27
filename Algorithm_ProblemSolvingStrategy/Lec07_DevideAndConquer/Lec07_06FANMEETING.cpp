#include <iostream>
#include <string>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {//num[]�� �ڸ��� �ø��� ó���Ѵ�
	num.push_back(0);
	//�ڸ��� �ø��� ó���Ѵ�
	for (int i = 0; i < num.size() - 1; i++) { //num.size()-1 �߿�
		if (num[i] < 0)	{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

//�� �� �ڿ����� ���� ��ȯ�Ѵ�
//�� �迭���� �� ���� �ڸ����� 1�� �ڸ��������� ������ ����Ǿ� �ִ�.
//��:multiply([3,2,1], [6,5,4])=123*456=56088=[8, 8, 0, 6, 5]
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += (a[i] * b[j]);
	normalize(c);
	return c;
}
//a+=b*(10^k)�� �����Ѵ�
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size() + k));
	for (int i = 0; i < length; i++)
		a[i + k] += b[i]; //�̷��� �����ν� ���� �ٸ� vector�� �������� �ʾƵ� �ǰ� ����������
						  //����ȭ (+��)             
	for (int i = 0; i < a.size(); i++)
		if (a[i] >= 10) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
}

//a-=b;�� �����Ѵ� a>=b�� �����Ѵ�
void subFrom(vector<int>& a, const vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size()) + 1);

	for (int i = 0; i < length; i++)
		a[i] -= b[i];
	//����ȭ

	for (int i = 0; i < a.size(); i++)
		if (a[i] < 0) {
			a[i] += 10;
			a[i + 1] -= 1;
		}
}
//�� �� ������ ���� ��ȯ�Ѵ�
//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)�� ����
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	//a�� b���� ª�� ��� ���� �ٲ۴�
	if (an < bn)
		return karatsuba(b, a);

	//���� ���:a�� b�� ����ִ� ���
	if (an == 0 || bn == 0)
		return vector<int>();

	//���� ���:a�� ���� ª�� ��� O(n^2) �������� �����Ѵ�
	if (an <= 5)
		return multiply(a, b);

	int half = an / 2;
	//a�� b�� �ؿ��� half�ڸ��� �������� �и��Ѵ�

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2=a1*b1
	vector<int> z2 = karatsuba(a1, b1);

	//z0=a0*b0
	vector<int> z0 = karatsuba(a0, b0);

	//a0=a0+a1
	//b0=b0+b1

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	//z1=(a0+a1)*(b0+b1)-z0-z2
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//result=z0+z1*10^half+z2*10^(half*2)
	vector<int> result;
	addTo(result, z0, 0);
	addTo(result, z1, half);
	addTo(result, z2, half + half);

	return result;
}
int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; ++i) B[M-i-1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++allHugs;
	return allHugs;
}

int main(void) {
	int c;
	cin >> c;
	cin.ignore(256, '\n');
	vector<int> answer;
	vector<int>::iterator iter;
	vector<int> result;

	for (int i = 0; i < c; i++) {
		result.clear();
		answer.push_back(0);

		// string���� �޾Ƽ� int�� �迭�� ��ȯ
		string mem_list;
		string fan_list;
		getline(cin, mem_list);
		getline(cin, fan_list);

		int M = mem_list.size();
		int F = fan_list.size();

		vector<int> arr_m(M), arr_f(F);
		for (int j = 0; j < M; j++) // 200,000 // M�̸� 1, F�̸� 0
			arr_m[j] = (mem_list[j] == 'M');
		for (int j = 0; j < F; j++) // 200,000 // F�� �ݴ�� ����
			arr_f[j] = (fan_list[F - j - 1] == 'M');

		vector<int> tmp_vector = multiply(arr_m, arr_f);
		result = karatsuba(arr_m, arr_f); // karatsuba ����
		result.resize(M + F - 1);
		result.resize(result.size() - M + 1);

		int k = 0;
		for (int j = result.size() - 1; k <= F - M; --j) {
			k++;
			if (result[j] == 0)
				++answer[i];
		}
	}

	for (iter = answer.begin(); iter != answer.end(); iter++)
		cout << *iter << endl;
	return 0;

}