#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSum(vector<int> &A, int target)
{
    sort(A.begin(), A.end());
    auto n = A.size();
    int result = 0;
    for (auto i = 0; i < n - 2; ++i)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            auto sum = A[i] + A[l] + A[r];
            if (sum > target)
                --r;
            else
            {
                result += (r - l);
                ++l;
            }
        }
    }
    return result;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 8;
    cout << threeSum(v, target);
}