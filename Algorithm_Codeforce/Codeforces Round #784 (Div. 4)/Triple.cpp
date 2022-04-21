#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums(200000, 0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int length;
        cin >> length;
        bool result = false;

        for (int j = 0; j < length; j++)
        {
            int num;
            cin >> num;
            nums[num]++;
            if (nums[num] >= 3)
            {
                result = true;
                number = num;
            }
        }
        if (result)
            cout << number << "\n";
        else
            cout << "-1\n";
        nums.clear();
    }
}