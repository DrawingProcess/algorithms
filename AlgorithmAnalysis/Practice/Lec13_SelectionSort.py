def selectionsort(n, s):
    for i in range(n):
        smallest = i
        for j in range(i+1, n):
            if (s[j] < s[smallest]):
                smallest = j
        tmp = s[i]
        s[i] = s[smallest]
        s[smallest] = tmp

s=[3,2,5,7,1,9,4,6,8]
n = len(s)
selectionsort(n, s)
print(s)