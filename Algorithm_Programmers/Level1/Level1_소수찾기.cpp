#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(1000001, false);
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {// i�� �������� n���� i�� ����
                prime[j] = 1; // i�� ��� �����ϱ�
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!prime[i]) answer++;
    }
    return answer;
}

//// ii) �ð��ʰ�
//bool isPrime(int n) {
//    if (n == 0 || n == 1) return false;
//    // for (int i = 2; i <= n / 2; i++)
//    for (int i = 2; i * i <= n; i++) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//int solution(int n) {
//    int answer = 0;
//    for (int i = 1; i <= n; i++) {
//        if (isPrime(i)) answer++;
//    }
//    return answer;
//}
int main() {
    int n = 5;
    cout << solution(n);
}