#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    int i = 2;
    while(i*i <= num) {
        if (num % i == 0)
            return false;
        i++;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> result;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (isPrime(nums[i] + nums[j] + nums[k])) {
                    answer++;
                }
            }
        }
    }
    return answer;
}
int main() {
    vector<int> nums = { 1,2,3,4 };
    // result: 1
    cout << solution(nums);
}