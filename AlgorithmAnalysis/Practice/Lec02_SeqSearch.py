def seqsearch(s,x):
    location = 0
    while (location < len(s) and s[location] != x):
        location += 1
    if (location >= len(s)):
        location = -1
    return location
s = [3, 5, 2, 1, 7, 9]
loc = seqsearch(s, 9)
print(loc)
print(s[loc])