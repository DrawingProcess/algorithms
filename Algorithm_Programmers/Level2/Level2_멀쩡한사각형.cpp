#include <iostream>
using namespace std;

using namespace std;

long long gcd(int a, int b)
{
    long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long solution(int w, int h)
{
    long long W = static_cast<long long>(w);
    long long H = static_cast<long long>(h);
    long long tmp = (w + h) - gcd(w, h);

    return (W * H) - tmp;
}

int main()
{
    cout << solution(8, 12);
    return 0;
}