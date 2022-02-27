def exchangesort(n, s):
    for i in range(n):
        for j in range(i+1, n):
            if (s[j] < s[i]):
                tmp = s[i]
                s[i] = s[j]
                s[j] = tmp

s=[3,2,5,7,1,9,4,6,8]
n = len(s)
exchangesort(n, s)
print(s)
