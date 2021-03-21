def mergeSort (n, S):
    mid = n // 2; high = n - mid
    # left = [0 for i in range(h)]
    # right = [0 for i in range(m)]
    if (n > 1):
        left = S[:mid]
        right = S[mid:]
        mergeSort(mid, left)
        mergeSort(high, right)
        merge(mid, high, left, right, S)

def merge(mid, high, left, right, S):
    i = 0; j = 0; k = 0
    while (i < mid and j < high):
        if (left[i] < right[j]):
            S[k] = left[i]
            i += 1
        else:
            S[k] = right[j]
            j += 1
        k += 1
    while i < mid:
        S[k] = left[i]
        i += 1
        k += 1
    while j < high:
        S[k] = right[j]
        j += 1
        k += 1


s = [3,5,2,9,10,14,4,8]
mergeSort(8, s)
print(s)
