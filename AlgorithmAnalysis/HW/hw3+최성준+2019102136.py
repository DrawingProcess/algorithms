# (1) 8쪽: [실습프로그램] 빠른정렬 프로그램을 python으로 완성
def quickSort(s, low, high):
    pivot = low
    if (high > low):
        partition(s, low, high)
        quickSort(s, low, pivot-1)
        quickSort(s, pivot+1, high)
def partition(s, low, high):
    pivot = s[low]
    j = low
    for i in range(low+1, high+1):
        if s[i] < pivot:
            j += 1
            temp = s[i]
            s[i] = s[j]
            s[j] = temp
    pivot = j
    temp = s[low]
    s[low] = s[pivot]
    s[pivot] = temp
s = [3, 5, 2, 9, 10, 14, 4, 8]
quickSort(s, 0, 7)
print(s)

# ----------------------------------------------------------------------------
# (2) 30쪽: [실습프로그램] 큰 정수 곱셈 알고리즘을 python으로 완성(threshold = 4)
def digit(num):
    count = 0
    while (num % 10 != 0 or num // 10 != 0):
        num = num // 10
        count += 1
    return count
def prod(U, V):
    threshold = 4
    n = max(digit(U), digit(V))
    if (U == 0 or V == 0): return 0
    elif (n <= threshold):
        return U * V
    else:
        m = n // 2
        x = U // 10 ** m; y = U % 10 ** m
        w = V // 10 ** m; z = V % 10 ** m
        return prod(x, w) * 10 ** (2*m) \
            + (prod(x, z) + prod(w, y)) * 10 ** m \
            +  prod(y, z)
a = 1234567812345678
b = 2345678923456789
print(prod(a,b))
print(a*b)
