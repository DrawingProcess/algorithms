/*
최대공약수(GCD, Greatest Common Divisor)
# 한줄요약
- 최대공약수를 구할 땐 유클리드 호제법을 이용하자.

# 개념
- 최대공약수는 A와 B의 공통된 약수 중에서 가장 큰 정수이다.
- 최대공약수가 1인 두 수를 서로소(Coprime)라고 한다.
- 3개 이상의 수에 대한 최대공약수를 구해야 하는 경우 GCD(GCD(A, B), C) 이런 방식으로 2개씩 묶어서 계산하면 된다.

@ 최대공약수를 구하는 방법
- 유클리드 호제법(Euclidean algorithm) 이용
- 이는 gcd(a, b) -> gcd(b, a%b) 이를 반복적으로 계속 진행하여, 오른쪽 인자의 값이 0일 때 왼쪽 인자를 반환하는데
   이것이 최대공약수이다.
- a < b 인 경우 둘의 위치를 swap 시킨뒤 계산되도록 하는 코드들이 간혹 있는데, 이 과정은 필요가 없다.
   a < b 일 때 a%b = a가 되기 때문에 계산중 알아서 swap이 일어나기 때문이다.
*/
// recursion
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
// non-recursion
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a; // if b == 0, gcd = a
}

/*
최소공배수(LCM, Least Common Multiple)
# 한줄요약
- 최소공배수를 구할 땐 유클리드 호제법으로 최대공약수 G를 구하고, L x G = A x B 를 이용해 L을 구하자.

# 개념
- 최소공배수는 A와 B의 공통된 배수 중에서 가장 작은 정수이다.
- 최대공약수와 달리 최소공배수는 두 수 A, B보다 큰 수가 나올 수 있기 때문에 저장할 때 적절한 자료형을 선택해야한다.
   L = (A x B) / G 에 의해서 (A x B)의 값이 int형을 넘는지 안넘는지 체크해야함.

@ 최소공배수를 구하는 방법
- 최대공약수를 구하는 방법을 응용하면 쉽게 구할 수 있다. L x G = A x B 이므로 L = (A x B) / G 이다.
- G는 유클리드 호제법으로 구하여 사용하자.
*/
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
