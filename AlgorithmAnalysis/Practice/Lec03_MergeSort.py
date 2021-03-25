def mergeSort(lst):
    if len(lst) <= 1:
        return lst

    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]

    left = mergeSort(left)
    right = mergeSort(right)
    return merge(left, right)

def merge(left, right):
    result = []
    i = 0; j = 0
    while( i < len(left) and j < len(right)):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    if i == len(left): result += right[j:len(right)]
    if j == len(right): result += left[i:len(left)]
    return result

s = [3,5,2,9,10,14,4,8]
s = mergeSort(s)
print(s) 