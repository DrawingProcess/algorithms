#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int length;
        cin >> length;
        vector<int> nums;
        for (int j = 0; j < length; j++)
        {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        bool answer = false, odd = nums[0] % 2, even = nums[1] % 2;
        for (int j = 2; j < nums.size(); j++)
        {
            if (j % 2 == 0){
                if (nums[j] % 2 == odd)
                    continue;
                else
                {
                    cout << "NO\n";
                    answer = true;
                    break;
                }
            }
            else
            {
                if (nums[j] % 2 == even)
                    continue;
                else
                {
                    cout << "NO\n";
                    answer = true;
                    break;
                }
            }
        }
        if (!answer)
            cout << "YES\n";
    }
}