#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    vector<int> possibleNumber;
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 0; i < numbers.size(); i++)
        {
            possibleNumber.push_back(stoi(numbers.substr(0, i + 1)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    sort(possibleNumber.begin(), possibleNumber.end());
    possibleNumber.erase(unique(possibleNumber.begin(), possibleNumber.end()), possibleNumber.end());

    for (int i = 0; i < possibleNumber.size(); i++)
    {
        if (IsPrime(possibleNumber[i]))
            answer++;
    }

    return answer;
}
