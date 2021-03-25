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