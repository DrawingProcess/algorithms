#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> nums;
    int t, tmp;
    cin >> t;
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        if (s == "push")
        {
            cin >> tmp;
            nums.push_back(tmp);
        }
        else if (s == "pop")
        {
            if (nums.empty())
                cout << "-1\n";
            else{
                cout << nums[nums.size() - 1] << "\n";
                nums.pop_back();
            }
        }
        else if (s == "size"){
            cout << nums.size() << "\n";
        }
        else if (s == "empty"){
            cout << nums.empty() << "\n";
        }
        else if (s == "top"){
            cout << nums[nums.size() - 1] << "\n";
        }
    }
}