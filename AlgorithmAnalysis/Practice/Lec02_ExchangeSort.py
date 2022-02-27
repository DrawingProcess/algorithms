def exchangesort(n, s):
    i = 0
    while (i < n):
        j = i + 1
        while (j < n):
            if s[j] < s[i]:
                temp = s[i]
                s[i] = s[j]
                s[j] = temp
            j += 1
        i += 1

s = [3,2,5,7,1,9,4,6,8]
n = len(s)
exchangesort(n, s)           
print(s)
