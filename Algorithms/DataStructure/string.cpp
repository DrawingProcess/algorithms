#include <iostream>
using namespace std;

/*
1. 문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
2. 문자열 길이를 구하는 함수
3. 문자열 뒤에 다른 문자열 붙이기
4. 문자열 내에 포함되어 있는 문자열 구하기
5. 문자열이 같은지 비교
6. 문자열 크기 비교 (사전 순)
*/
class MyString
{
    char *str;
    int len;

public:
    MyString(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
    MyString(const char *s);
    MyString(const MyString &s);
    ~MyString();

    void add_MyString(const MyString &s);  // str 뒤에 s 를 붙인다.
    void copy_MyString(const MyString &s); // str 에 s 를 복사한다.
    int strlen();                      // 문자열 길이 리턴
};
MyString::MyString(char c, int n){
    len = n;
    str = new char[len + 1];
    for (i = 0; i < len; i++)
    {
        str[i] = c;
    }
    str[i] = (char)NULL;
}
MyString::~MyString(){
    if (str != NULL){
        delete[] str;
    }
}