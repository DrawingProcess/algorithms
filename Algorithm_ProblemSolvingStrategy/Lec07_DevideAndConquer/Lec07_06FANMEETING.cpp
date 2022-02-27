#include <iostream>
#include <string>
#include <vector>
using namespace std;

void normalize(vector<int>& num) {//num[]의 자릿수 올림을 처리한다
	num.push_back(0);
	//자릿수 올림을 처리한다
	for (int i = 0; i < num.size() - 1; i++) { //num.size()-1 중요
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

//두 긴 자연수의 곱을 반환한다
//각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
//예:multiply([3,2,1], [6,5,4])=123*456=56088=[8, 8, 0, 6, 5]
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += (a[i] * b[j]);
	normalize(c);
	return c;
}
//a+=b*(10^k)를 구현한다
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size() + k));
	for (int i = 0; i < length; i++)
		a[i + k] += b[i]; //이렇게 함으로써 굳이 다른 vector를 선언하지 않아도 되고 간편해졌다
						  //정규화 (+만)             
	for (int i = 0; i < a.size(); i++)
		if (a[i] >= 10) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
}

//a-=b;를 구현한다 a>=b를 가정한다
void subFrom(vector<int>& a, const vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size()) + 1);

	for (int i = 0; i < length; i++)
		a[i] -= b[i];
	//정규화

	for (int i = 0; i < a.size(); i++)
		if (a[i] < 0) {
			a[i] += 10;
			a[i + 1] -= 1;
		}
}
//두 긴 정수의 곱을 반환한다
//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)의 원리
vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	//a가 b보다 짧을 경우 둘을 바꾼다
	if (an < bn)
		return karatsuba(b, a);

	//기저 사례:a나 b가 비어있는 경우
	if (an == 0 || bn == 0)
		return vector<int>();

	//기저 사례:a가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다
	if (an <= 5)
		return multiply(a, b);

	int half = an / 2;
	//a와 b를 밑에서 half자리와 나머지로 분리한다

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

		// string으로 받아서 int형 배열로 변환
		string mem_list;
		string fan_list;
		getline(cin, mem_list);
		getline(cin, fan_list);

		int M = mem_list.size();
		int F = fan_list.size();

		vector<int> arr_m(M), arr_f(F);
		for (int j = 0; j < M; j++) // 200,000 // M이면 1, F이면 0
			arr_m[j] = (mem_list[j] == 'M');
		for (int j = 0; j < F; j++) // 200,000 // F는 반대로 저장
			arr_f[j] = (fan_list[F - j - 1] == 'M');

		vector<int> tmp_vector = multiply(arr_m, arr_f);
		result = karatsuba(arr_m, arr_f); // karatsuba 실행
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