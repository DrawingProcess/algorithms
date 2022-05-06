#include <iostream>
using namespace std;

class string
{
    char *str;
    int len;

public:
    string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);  // str 뒤에 s 를 붙인다.
    void copy_string(const string &s); // str 에 s 를 복사한다.
    int strlen();                      // 문자열 길이 리턴
};
string::string(char c, int n){
    len = n;
    str = new char[len + 1];
    for (i = 0; i < len; i++)
    {
        str[i] = c;
    }
    str[i] = (char)NULL;
}
string::~string(){
    if (str != NULL){
        delete[] str;
    }
}