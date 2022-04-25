#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> nums;
    int t, num;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> num;
        if (num == 0)
            nums.pop();
        else
            nums.push(num);
    }
    int sum = 0;
    while (!nums.empty())
    {
        sum += nums.top();
        nums.pop();
    }
    cout << sum;
}