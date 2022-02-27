def digit(num):
    count = 0
    while (num % 10 != 0 or num // 10 != 0):
        num = num // 10
        count += 1
    return count

def prod(U, V):
    threshold = 987654321
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
