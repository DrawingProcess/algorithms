import time

# Recursive
def bin (n, k):
    if (k == 0 or n == k):
        return 1
    else:
        return bin(n-1, k-1) + bin(n-1, k)

# Dynamic Programming
def bin2 (n, k):
    B = [[0 for i in range(k+1)] for j in range(n+1)]
    for i in range(n+1):
        for j in range(min(i, k)+1):
            if (j == 0 or j == i):
                B[i][j] = 1
            else:
                B[i][j] = B[i - 1][j - 1] + B[i - 1][j]
    return B[n][k]

# Analysis Execute Time
Stime = time.time()
bin(200, 5)
Ltime = time.time()
Atime = Ltime - Stime

Stime = time.time()
bin2(200, 5)
Ltime = time.time()
Btime = Ltime - Stime

print(f'{Atime:10.10f}\n{Btime:10.10f}')
print(bin(10, 5), bin2(10, 5))