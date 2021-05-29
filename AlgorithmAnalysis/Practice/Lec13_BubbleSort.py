def bubblesort(n, s):
    for i in range(n, 0, -1):
        for j in range(1, i):
            if (s[j-1] > s[j]):
                tmp = s[j-1]
                s[j-1] = s[j]
                s[j] = tmp

s=[3,2,5,7,1,9,4,6,8]
n = len(s)
bubblesort(n, s)
print(s)