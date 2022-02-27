def insesrtionsort(n, S):
    i = 1
    while (i < n):
        x = S[i]
        j = i - 1
        while (j >= 0 and S[j] > x):
            S[j+1] = S[j]
            j -= 1
        S[j+1] = x
        i += 1

s=[3,2,5,7,1,9,4,6,8]
n = len(s)
insesrtionsort(n, s)
print(s)
