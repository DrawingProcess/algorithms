#include <iostream>
#include <list>
using namespace std;
int main(){
    list<char> li;
    string s;
    cin >> s;
    for (auto str: s){
        li.push_back(str);
    }
}